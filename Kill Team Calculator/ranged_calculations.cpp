#include "ranged_calculations.h"
#include "die.h"

#include <random>

ranged_results ranged_calculations::calculate_kill_chance(const ranged_config& cf) {
    constexpr int runs = 1000000;
    int kills = 0;
	int total_wounds = 0;

    static std::random_device rd;
    static std::seed_seq seq{
       rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()
    };
    static std::mt19937_64 gen(seq);    

    std::uniform_int_distribution<> dice_distrib(1, 6);

    const auto& attacker = cf.attacker;
	const auto& defender = cf.defender;

	uint16_t atk_crit_threshold = attacker.is_lethal ? attacker.lethality : 6;
    const auto full_crit_dmg = attacker.crit_dmg + attacker.devestating;

	uint16_t atk_normal_threshold = std::min(attacker.ws, atk_crit_threshold);
    bool atk_reroll_individual_die_aggressively = attacker.rerolling_agressively;

    // Do some ev calculations to see if we should be rerolling aggressively even if not fishing for crits.
    // Will have to be done after knowing the roll for ceaseless but can be done for an individual die basis here
    if (!atk_reroll_individual_die_aggressively)
    {
		atk_reroll_individual_die_aggressively = ((7 - atk_crit_threshold) * full_crit_dmg) > ((atk_normal_threshold - 1) * attacker.normal_dmg);
    }

    #pragma omp parallel for reduction(+:kills, total_wounds)
    for (auto run = 0; run < runs; ++run)
    {
        // Attacking rolls
        uint16_t atk_crits = 0;
        uint16_t atk_normal = 0;
		uint16_t attacks = attacker.attacks;
		die_counter atk_rerollable_die_tracker{};
        die_counter atk_locked_die_tracker{};
        
        { //scope atk section
            auto perform_roll = [&](die_counter& tracker)
                {
                    uint16_t roll = dice_distrib(gen);

                    tracker.add(roll);

                    if (roll >= atk_crit_threshold)
                    {
                        ++atk_crits;
                    }
                    else if (roll >= atk_normal_threshold && roll > 1)
                    {
                        ++atk_normal;
                    }
                };

            if (attacker.accurate > 0)
            {
                atk_normal += std::min(attacker.accurate, attacks);
                attacks -= std::min(attacker.accurate, attacks);
            }

            for (uint16_t attack = 0; attack < attacks; ++attack)
            {
                perform_roll(atk_rerollable_die_tracker);
            }

            const auto reroll_limit = atk_reroll_individual_die_aggressively ? atk_crit_threshold - 1 : atk_normal_threshold - 1;
            if (attacker.relentless)
            {
                for (auto roll_value = 1; roll_value <= reroll_limit; ++roll_value)
                {
                    auto rolls = atk_rerollable_die_tracker[roll_value];
                    atk_rerollable_die_tracker[roll_value] = 0;
                    while (rolls > 0)
                    {
                        if (roll_value >= atk_normal_threshold)
                        {
                            --atk_normal;
                        }

                        perform_roll(atk_locked_die_tracker);
                        --rolls;
                    }

                }
            }
            else if (attacker.ceaseless)
            {
                auto best_die = atk_rerollable_die_tracker.max_under_number(atk_crit_threshold);

                if (best_die.roll_value >= atk_normal_threshold)
                {
                    auto potential_best_die = atk_locked_die_tracker.max_under_number(atk_normal_threshold);
                    const auto gain_from_upgrade_per_die = full_crit_dmg - attacker.normal_dmg;
                    const auto crit_rolls = 7 - atk_crit_threshold;
                    const auto normal_rolls = 7 - atk_normal_threshold - crit_rolls;
                    const auto fail_rolls = atk_normal_threshold - 1;

                    if (attacker.rerolling_agressively)
                    {
                        // We are rerolling aggressively in this branch so we are fishing for crits.
                        // This means we should check the best case scenario where all rolls become crits
                        const auto gain_from_upgrade_normals = best_die.rolls * gain_from_upgrade_per_die;
                        const auto gain_from_upgrade_fails = potential_best_die.rolls * full_crit_dmg;

                        if (gain_from_upgrade_fails > gain_from_upgrade_normals)
                        {
                            best_die = potential_best_die;
                        }
                    }
                    else
                    {
                        const auto gain_from_upgrade_normals = best_die.rolls * ((normal_rolls * attacker.normal_dmg) + (crit_rolls * full_crit_dmg) - attacker.normal_dmg * 6 /*Guarenteed chance to 'lose' the original roll*/);
                        const auto gain_from_upgrade_fails = potential_best_die.rolls * ((normal_rolls * attacker.normal_dmg) + (crit_rolls * full_crit_dmg));

                        if (gain_from_upgrade_fails > gain_from_upgrade_normals)
                        {
                            best_die = potential_best_die;
                        }
                    }
                }

                atk_rerollable_die_tracker[best_die.roll_value] = 0;

                auto rolls = best_die.rolls;
                while (rolls > 0)
                {
                    if (best_die.roll_value >= atk_normal_threshold)
                    {
                        --atk_normal;
                    }

                    perform_roll(atk_locked_die_tracker);
                    --rolls;
                }
            }

            if (!attacker.relentless && (attacker.balanced || attacker.faction_rerolls > 0))
            {
                uint16_t rolls = (attacker.balanced ? 1 : 0) + attacker.faction_rerolls;
                if (rolls > 0)
                {
                    for (auto roll_value = 1; roll_value <= reroll_limit; ++roll_value)
                    {
                        while (rolls > 0 && atk_rerollable_die_tracker[roll_value] > 0)
                        {
                            --atk_rerollable_die_tracker[roll_value];
                            --rolls;

                            if (roll_value >= atk_normal_threshold)
                            {
                                --atk_normal;
                            }

                            perform_roll(atk_locked_die_tracker);
                        }

                        if (rolls == 0)
                        {
                            break;
                        }
                    }

                }
            }


            if (defender.obscured)
            {
                atk_normal += atk_crits;
                atk_crits = 0;
                if (atk_normal > 0)
                {
                    --atk_normal;
                }
            }
        }

        // At this point the attacking die are locked in calculate any automatic damage.

        uint16_t attack_damage = 0;
        if (attacker.devestating > 0)
        {
            attack_damage += atk_crits * attacker.devestating;
        }

        // Defence time

        uint16_t def_normal = 0;
        uint16_t def_crits = 0;
        uint16_t defence_die = 3;
		die_counter def_rerollable_die_tracker{};
        die_counter def_locked_die_tracker{};

        { //scope def section
            auto perform_def_roll = [&](die_counter& tracker)
                {
                    uint16_t roll = dice_distrib(gen);

                    tracker.add(roll);

                    if (roll >= atk_crit_threshold)
                    {
                        ++def_crits;
                    }
                    else if (roll >= atk_normal_threshold && roll > 1)
                    {
                        ++def_normal;
                    }
                };

			const bool def_reroll_individual_die_aggressively = defender.rerolling_aggressively ? attacker.crit_dmg > attacker.normal_dmg : attacker.crit_dmg > (attacker.normal_dmg * defender.save - 1);

            if (defender.cover && !def_reroll_individual_die_aggressively)
            {
                ++def_normal;
                --defence_die;
            }

            if (attacker.piercing > 0)
            {
                defence_die -= std::min(attacker.piercing, defence_die);
            }

            for (uint16_t def = 0; def < defence_die; ++def)
            {
                perform_def_roll(def_rerollable_die_tracker);
            }



            uint16_t def_rerolls = defender.faction_reroll;
			const bool reroll_threshold = def_reroll_individual_die_aggressively ? 6 : defender.save;

            for (auto roll_value = 1; roll_value < reroll_threshold; ++roll_value)
            {
				auto& rolls = def_rerollable_die_tracker[roll_value];
                while (def_rerolls > 0 && rolls > 0 && def_crits < atk_crits)
                {
					perform_def_roll(def_locked_die_tracker);
                    --def_rerolls;
					--rolls;
                }

                if (def_rerolls == 0 || def_crits >= atk_crits)
                {
                    break;
				}
            }

            //Optimise use of defence rolls

            // If attack_normal >= attack_crit use normals to block normals first then 2x normals to block crits then crits to block normals then crits to crits
            if (attacker.normal_dmg >= attacker.crit_dmg)
            {
                //tbd do this not in a silly while loop
                while (atk_normal > 0 && def_normal > 0)
                {
                    --atk_normal;
                    --def_normal;
                }

                while (atk_crits > 0 && def_normal > 1)
                {
                    --atk_crits;
                    def_normal -= 2;
                }

                while (atk_normal > 0 && def_crits > 0)
                {
                    --atk_normal;
                    --def_crits;
                }

                while (atk_crits > 0 && def_crits > 0)
                {
                    --atk_crits;
                    --def_crits;
                }
            }

            // If attack_crit > attack_normal use crits to block crits then crits to block normals then either 2x normals to crits then 1x to block normals or vice versa depending on if attack_crit > 2x attack_normal
            else
            {
                while (atk_crits > 0 && def_crits > 0)
                {
                    --atk_crits;
                    --def_crits;
                }

                while (atk_normal > 0 && def_crits > 0)
                {
                    --atk_normal;
                    --def_crits;
                }

                if (attacker.crit_dmg > 2 * attacker.normal_dmg)
                {
                    while (atk_crits > 0 && def_normal > 1)
                    {
                        --atk_crits;
                        def_normal -= 2;
                    }

                    while (atk_normal > 0 && def_normal > 0)
                    {
                        --atk_normal;
                        --def_normal;
                    }
                }
                else
                {
                    while (atk_normal > 0 && def_normal > 0)
                    {
                        --atk_normal;
                        --def_normal;
                    }

                    while (atk_crits > 0 && def_normal > 1)
                    {
                        --atk_crits;
                        def_normal -= 2;
                    }
                }
            }
        }

        attack_damage += (attacker.normal_dmg * atk_normal) + (attacker.crit_dmg * atk_crits);

		total_wounds += std::min(attack_damage, defender.wounds);

        if (attack_damage >= defender.wounds)
        {
            kills++;
        }
    }

    ranged_results results {};
	results.average_wounds = static_cast<double>(total_wounds) / static_cast<double>(runs);
	results.kill_chance = static_cast<double>(kills) / static_cast<double>(runs);
	return results;
}