#pragma once
#include <string>

struct ranged_attacker_config
{
	uint16_t attacks;
	uint16_t ws;
	uint16_t normal_dmg;
	uint16_t crit_dmg;
	uint16_t faction_rerolls;
	bool rerolling_agressively;
	uint16_t accurate;
	bool balanced;
	bool ceaseless;
	uint16_t devestating;
	bool is_lethal;
	uint16_t lethality;
	uint16_t piercing;
	bool punishing;
	bool relentless;
	bool rending;
	bool severe;
};

struct ranged_defender_config
{
	uint16_t wounds;
	uint16_t save;
	bool cover;
	bool obscured;
	uint16_t faction_reroll;
	bool rerolling_aggressively;
};

struct ranged_config
{
	ranged_attacker_config attacker;
	ranged_defender_config defender;
};

struct ranged_results
{
	double kill_chance;
	double average_wounds;
};

class ranged_calculations
{
public:
	static ranged_results calculate_kill_chance(const ranged_config& cf);
};