#include "ranged_calculations.h"
#include <random>

ranged_results ranged_calculations::calculate_kill_chance(const ranged_config& cf) {
    constexpr int runs = 100000;
    int kills = 0;
	int total_wounds = 0;

    static std::random_device rd;
    static std::seed_seq seq{
       rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()
    };
    static std::mt19937_64 gen(seq);    

    std::uniform_int_distribution<> dice_distrib(1, 6);

    auto& attacker = cf.attacker;
	auto& defender = cf.defender;

	uint16_t atk_crit_threshold = attacker.is_lethal ? attacker.lethality : 6;

    for (auto run = 0; run < runs; ++run)
    {
        // Roll atk and defence
        uint16_t atk_crits = 0;
        uint16_t atk_normal = 0;
		uint16_t atk_rerollable_fails = 0;
		uint16_t attacks = attacker.attacks;

		if (attacker.accurate > 0 && !attacker.rerolling_agressively)
        {
			atk_normal += std::min(attacker.accurate, attacks);
			attacks -= std::min(attacker.accurate, attacks);
        }

        for (uint16_t attack = 0; attack < attacks; ++attack)
        {
            uint16_t roll = dice_distrib(gen);

            if (roll >= atk_crit_threshold)
            {
                ++atk_crits;
            }
            else if (roll >= attacker.ws && roll > 1)
            {
                ++atk_normal;
            }
            else
            {
                ++atk_rerollable_fails;
            }
        }

        /*tbd: attaker rerolls*/

        uint16_t def_normal = 0;
        uint16_t def_crits = 0;
        uint16_t def_rerollable_fails = 0;
        uint16_t defence_die = 3;

        if (defender.obscured)
        {
            atk_normal += atk_crits;
			atk_crits = 0;
            if (atk_normal > 0)
            {
                --atk_normal;
            }
		}

		if (defender.cover)
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
            uint16_t roll = dice_distrib(gen);

            if (roll == 6)
            {
                ++def_crits;
            }
            else if (roll >= defender.save && roll > 1)
            {
                ++def_normal;
            }
            else
            {
                ++def_rerollable_fails;
            }
        }

        uint16_t attack_damage = 0;
        if (attacker.devestating > 0)
        {
            attack_damage += atk_crits * attacker.devestating;
        }

		uint16_t def_rerolls = defender.faction_reroll;
		while (def_rerolls > 0 && def_rerollable_fails > 0)
        {
            uint16_t roll = dice_distrib(gen);
            --def_rerolls;
            --def_rerollable_fails;
            if (roll == 6)
            {
                ++def_crits;
               
            }
            else if (roll >= defender.save && roll > 1)
            {
                ++def_normal;
                --def_rerollable_fails;
            }
        }

        //TBD: Figure out whether to reroll successful defence die;

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