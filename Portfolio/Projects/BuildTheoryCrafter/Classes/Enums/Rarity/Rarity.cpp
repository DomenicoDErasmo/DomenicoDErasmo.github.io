// Domenico D'Erasmo
// 14 May 2019
// Implementation file for Rarity Enumeration and Functions

#include <iostream>

#include "Rarity.h"

Rarity StringToRarity(std::string input_string)
{
	if (input_string == "gold")
	{
		return gold;
	}
	else if (input_string == "purple")
	{
		return purple;
	}
	else if (input_string == "blue")
	{
		return blue;
	}
	else if (input_string == "green")
	{
		return green;
	}
	else
	{
		return white;
	}
}

std::string RarityToString(Rarity input_rarity)
{
	if (input_rarity == gold)
	{
		return "gold";
	}
	else if (input_rarity == purple)
	{
		return "purple";
	}
	else if (input_rarity == blue)
	{
		return "blue";
	}
	else if (input_rarity == green)
	{
		return "green";
	}
	else
	{
		return "white";
	}
}