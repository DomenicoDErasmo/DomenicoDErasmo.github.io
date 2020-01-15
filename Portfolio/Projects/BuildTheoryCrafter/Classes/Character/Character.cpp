// Domenico D'Erasmo
// 18 April 2019
// Implementation file for Character class

#include <iostream>
#include <fstream>

#include "Character.h"

Character::Character()
{
	account_level = 1;
	level = 1;
	number_of_equipped_cards = 0;
	number_of_unlocked_cards = 1;
	usb_level = 1;
}

void Character::SetUnlockedCardsFromLevel(int input_level)
{
	if (input_level >= 60)
	{
		SetNumberOfUnlockedCards(12);
	}
	else if (input_level >= 55 && input_level <= 59)
	{
		SetNumberOfUnlockedCards(11);
	}
	else if (input_level >= 50 && input_level <= 54)
	{
		SetNumberOfUnlockedCards(10);
	}
	else if (input_level >= 45 && input_level <= 49)
	{
		SetNumberOfUnlockedCards(9);
	}
	else if (input_level >= 38 && input_level <= 44)
	{
		SetNumberOfUnlockedCards(8);
	}
	else if (input_level >= 31 && input_level <= 37)
	{
		SetNumberOfUnlockedCards(7);
	}
	else if (input_level >= 25 && input_level <= 30)
	{
		SetNumberOfUnlockedCards(6);
	}
	else if (input_level >= 19 && input_level <= 24)
	{
		SetNumberOfUnlockedCards(5);
	}
	else if (input_level >= 15 && input_level <= 19)
	{
		SetNumberOfUnlockedCards(4);
	}
	else if (input_level >= 10 && input_level <= 14)
	{
		SetNumberOfUnlockedCards(3);
	}
	else if (input_level >= 5 && input_level <= 9)
	{
		SetNumberOfUnlockedCards(2);
	}
	else
	{
		SetNumberOfUnlockedCards(1);
	}
}

Card& Character::GetCardFromIndex(int input_card_index)
{
	return cards[input_card_index];
}

int Character::GetAccountLevel()
{
	return account_level;
}

int Character::GetLevel()
{
	return level;
}

int Character::GetNumberOfEquippedCards()
{
	return number_of_equipped_cards;
}

int Character::GetNumberOfUnlockedCards()
{
	return number_of_unlocked_cards;
}

int Character::GetUSBLevel()
{
	return usb_level;
}

Outfit& Character::GetOutfit()
{
	return outfit;
}

StatValue& Character::GetBaseStatFromIndex(int input_stat_index)
{
	return base_stats[input_stat_index];
}

StatValue& Character::GetIllustrationBoostFromIndex(int input_illustration_boost_index)
{
	return illustration_boosts[input_illustration_boost_index];
}

StatValue& Character::GetLevelStatFromIndex(int input_level_stat_index)
{
	return level_stats[input_level_stat_index];
}

StatValue& Character::GetStatFromIndex(int input_stat_index)
{
	return stats[input_stat_index];
}

std::string Character::GetName()
{
	return name;
}

Trinket Character::GetTrinketFromIndex(int input_stat_index)
{
	return trinkets[input_stat_index];
}

void Character::InitializeLevelStats()
{
	for (int stat_index = 13; stat_index < 18; stat_index++)
	{
		StatCategory stat = static_cast<StatCategory> (stat_index);
		level_stats[stat_index - 13].SetCategory(stat);
	}

}

void Character::InitializeThirteenStats()
{
	for (int stat_index = 0; stat_index < 13; stat_index++)
	{
		StatCategory stat = static_cast<StatCategory> (stat_index);
		base_stats[stat_index].SetCategory(stat);
		illustration_boosts[stat_index].SetCategory(stat);
		stats[stat_index].SetCategory(stat);
	}
}

void Character::InitializeTrinketStats()
{
	trinkets[0].SetStatCategory(attack);
	trinkets[1].SetStatCategory(defense);
	trinkets[2].SetStatCategory(faith);
}

void Character::InitializeStatCategories()
{
	InitializeLevelStats();
	InitializeThirteenStats();
	InitializeTrinketStats();
}

void Character::PrintStatsToFile()
{
	std::ofstream output;
	output.open("Stats.txt");
	output << name << "\nStat -- Amount\n";
	for (int stat_index = 0; stat_index < 13; stat_index++)
	{
		output << StatToString(stats[stat_index].GetCategory()) << " -- " << stats[stat_index].GetAmount() << "\n";
	}
	for (int stat_index = 0; stat_index < 5; stat_index++)
	{
		output << StatToString(level_stats[stat_index].GetCategory()) << " -- " << level_stats[stat_index].GetAmount() << "\n";
	}
}

void Character::SetAccountLevel(int input_account_level)
{
	account_level = input_account_level;
}

void Character::SetLevel(int input_level)
{
	level = input_level;
	SetUnlockedCardsFromLevel(level);
}

void Character::SetName(std::string input_name)
{
	name = input_name;
}

void Character::SetNumberOfEquippedCards(int input_number_of_equipped_cards)
{
	number_of_equipped_cards = input_number_of_equipped_cards;
}

void Character::SetNumberOfUnlockedCards(int input_number_of_unlocked_cards)
{
	number_of_unlocked_cards = input_number_of_unlocked_cards;
}

void Character::SetOutfit(Outfit input_outfit)
{
	outfit = input_outfit;
}

void Character::SetUSBLevel(int input_usb_level)
{
	usb_level = input_usb_level;
}