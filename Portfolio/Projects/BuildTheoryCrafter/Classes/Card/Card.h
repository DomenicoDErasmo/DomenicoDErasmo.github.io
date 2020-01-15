// Domenico D'Erasmo
// 7 May 2019
// Interface file for Card Class

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>

#include "../CardConnection/CardConnection.h"
#include "../StatValue/StatValue.h"
#include "../Enums/Rarity/Rarity.h"

class Card
{

public:

	// Accessors
	CardConnection& GetCardConnectionFromIndex(int input_index);
	int GetLevel();
	int GetMaxCardConnections();
	int GetMaxStats();
	int GetUnlockedStats();
	Rarity GetRarity();
	StatValue& GetStatFromIndex(int input_index);
	std::string GetName();

	// Mutators
	void SetLevel(int input_level);
	void SetMaxStats(int input_max_stats);
	void SetUnlockedStats(int input_unlocked_stats);
	void SetRarity(Rarity input_rarity);

	// Auxiliary Functions
	void InitializeCardConnections();
	void ProcessCardConnectionFile(std::fstream& input_file, int input_index);
	void RemoveCardProperties();
	void SetMaxStatsFromRarity();
	void SetUnlockedStatsFromLevel();
	
private:

	int level;
	int max_card_connections;
	int max_stats;
	int unlocked_stats;
	Rarity rarity;
	std::string name;
	std::vector<CardConnection> card_connections;
	std::vector<StatValue> stats;
	
};

#endif // !CARD_H
