// Domenico D'Erasmo
// 18 April 2019
// Interface file for Character class

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

#include "../Card/Card.h"
#include "../StatValue/StatValue.h"
#include "../Trinket/Trinket.h"
#include "../Outfit/Outfit.h"

class Character
{

public:

	Character();

	// Accessors
	Card& GetCardFromIndex(int input_card_index);
	int GetAccountLevel();
	int GetLevel();
	int GetNumberOfEquippedCards();
	int GetNumberOfUnlockedCards();
	int GetUSBLevel();
	Outfit& GetOutfit();
	StatValue& GetBaseStatFromIndex(int input_stat_index);
	StatValue& GetStatFromIndex(int input_stat_index);
	StatValue& GetIllustrationBoostFromIndex(int input_illustration_boost_index);
	StatValue& GetLevelStatFromIndex(int input_level_stat_index);
	std::string GetName();
	Trinket GetTrinketFromIndex(int input_trinket_index);
	
	// Initialization
	void InitializeLevelStats();
	void InitializeTrinketStats();
	void InitializeThirteenStats();
	void InitializeStatCategories();
	
	// Mutators
	void SetAccountLevel(int input_account_level);
	void SetLevel(int input_level);
	void SetName(std::string input_name);
	void SetNumberOfEquippedCards(int input_number_of_equipped_cards);
	void SetNumberOfUnlockedCards(int input_number_of_unlocked_cards);
	void SetOutfit(Outfit input_outfit);
	void SetUSBLevel(int input_usb_level);

	// Auxiliary
	void PrintStatsToFile();
	void SetUnlockedCardsFromLevel(int input_level);

private:

	Card cards[12];
	int account_level;
	int level;
	int number_of_equipped_cards;
	int number_of_unlocked_cards;
	int usb_level;
	Outfit outfit;
	StatValue base_stats[13];
	StatValue illustration_boosts[13];
	StatValue level_stats[5];
	StatValue stats[13];
	std::string name;
	Trinket trinkets[3];
};

#endif // !CHARACTER_H
