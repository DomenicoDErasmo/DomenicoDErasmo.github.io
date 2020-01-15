// Domenico D'Erasmo
// 18 April 2019
// Implementation File for StatCategory Enumeration and Functions

#include <iostream>

#include "StatCategory.h"

StatCategory StringToStat(std::string input_string)
{
if (input_string == "health")
	{
		return health;
	}
	else if (input_string == "attack")
	{
		return attack;
	}
	else if (input_string == "defense")
	{
		return defense;
	}
	else if (input_string == "crit_chance")
	{
		return crit_chance;
	}
	else if (input_string == "crit_damage")
	{
		return crit_damage;
	}
	else if (input_string == "normal_attack")
	{
		return normal_attack;
	}
	else if (input_string == "science_attack")
	{
		return science_attack;
	}
	else if (input_string == "magic_attack")
	{
		return magic_attack;
	}
	else if (input_string == "normal_defense")
	{
		return normal_defense;
	}
	else if (input_string == "science_defense")
	{
		return science_defense;
	}
	else if (input_string == "magic_defense")
	{
		return magic_defense;
	}
	else if (input_string == "health_regen")
	{
		return health_regen;
	}
	else if (input_string == "move_speed")
	{
		return move_speed;
	}
	else if (input_string == "constitution")
	{
		return constitution;
	}
	else if (input_string == "power")
	{
		return power;
	}
	else if (input_string == "endurance")
	{
		return endurance;
	}
	else if (input_string == "agility")
	{
		return agility;
	}
	else if (input_string == "faith")
	{
		return faith;
	}
	else if (input_string == "date")
	{
		return date;
	}
	else
	{
		return choose;
	}
}

std::string StatToString(StatCategory input_stat_category)
{
	if (input_stat_category == health)
	{
		return "health";
	}
	else if (input_stat_category == attack)
	{
		return "attack";
	}
	else if (input_stat_category == defense)
	{
		return "defense";
	}
	else if (input_stat_category == crit_chance)
	{
		return "crit_chance";
	}
	else if (input_stat_category == crit_damage)
	{
		return "crit_damage";
	}
	else if (input_stat_category == normal_attack)
	{
		return "normal_attack";
	}
	else if (input_stat_category == science_attack)
	{
		return "science_attack";
	}
	else if (input_stat_category == magic_attack)
	{
		return "magic_attack";
	}
	else if (input_stat_category == normal_defense)
	{
		return "normal_defense";
	}
	else if (input_stat_category == science_defense)
	{
		return "science_defense";
	}
	else if (input_stat_category == magic_defense)
	{
		return "magic_defense";
	}
	else if (input_stat_category == health_regen)
	{
		return "health_regen";
	}
	else if (input_stat_category == move_speed)
	{
		return "move_speed";
	}
	else if (input_stat_category == constitution)
	{
		return "constitution";
	}
	else if (input_stat_category == power)
	{
		return "power";
	}
	else if (input_stat_category == endurance)
	{
		return "endurance";
	}
	else if (input_stat_category == agility)
	{
		return "agility";
	}
	else if (input_stat_category == faith)
	{
		return "faith";
	}
	else if (input_stat_category == date)
	{
		return "date";
	}
	else
	{
		return "choose";
	}

}
