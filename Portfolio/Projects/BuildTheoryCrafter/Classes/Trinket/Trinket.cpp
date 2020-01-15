// Domenico D'Erasmo
// 19 April 2019
// Implementation file for Trinket class

#include <iostream>
#include <algorithm>

#include "Trinket.h"

Trinket::Trinket()
{
	level = 1;
	max_level = 1;
	stat.SetCategory(faith);
}

int Trinket::GetLevel()
{
	return level;
}

int Trinket::GetMaxLevel()
{
	return max_level;
}

StatValue Trinket::GetStat()
{
	return stat;
}

void Trinket::SetLevel(int input_level)
{
	level = input_level;
	if (stat.GetCategory() == attack)
	{
		stat.SetAmount((double)level * 10);
	}
	else if (stat.GetCategory() == defense)
	{
		stat.SetAmount((double)level * 5);
	}
	else
	{
		stat.SetAmount(level);
	}
}

void Trinket::SetMaxLevel(int account_level)
{
	if (stat.GetCategory() == attack)
	{
		max_level = std::min((account_level - 28) / 2, 25);
	}
	else if (stat.GetCategory() == defense)
	{
		max_level = std::min((account_level - 29) / 2, 25);
	}
	else if (stat.GetCategory() == faith)
	{
		max_level = std::min((account_level - 30) / 2, 25);
	}
}

// Precondition: input_category is either attack, defense, or faith
void Trinket::SetStatCategory(StatCategory input_category)
{
	if (input_category == attack)
	{
		stat.SetCategory(attack);
	}
	else if (input_category == defense)
	{
		stat.SetCategory(defense);
	}
	else
	{
		stat.SetCategory(faith);
	}
}