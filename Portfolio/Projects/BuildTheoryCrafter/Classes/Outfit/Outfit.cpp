// Domenico D'Erasmo
// 24 April 2019
// Implementation of Outfit Class

#include <iostream>

#include "Outfit.h"

Outfit::Outfit()
{
	max_stats = 0;
	name = "";
}

int Outfit::GetMaxStats()
{
	return max_stats;
}

// Precondition: index < max_stats
StatValue Outfit::GetStatFromIndex(int index)
{
	return stats[index];
}

std::string Outfit::GetName()
{
	return name;
}

void Outfit::SetMaxStats(int input_max_stats)
{
	max_stats = input_max_stats;
}

void Outfit::SetName(std::string input_name)
{
	name = input_name;
}

Outfit& Outfit::operator = (const Outfit& right_outfit)
{
	max_stats = right_outfit.max_stats;
	name = right_outfit.name;
	for (int stat_index = 0; stat_index < max_stats; stat_index++)
	{
		stats[stat_index] = right_outfit.stats[stat_index];
	}

	return *this;
}