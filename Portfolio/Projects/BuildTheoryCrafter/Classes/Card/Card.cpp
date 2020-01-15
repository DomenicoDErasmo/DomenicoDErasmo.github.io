// Domenico D'Erasmo
// 7 May 2019
// Implementation file for Card Class

#include <fstream>
#include <iostream>
#include <limits>
#include <string>

#include "Card.h"
#include "../Miscellaneous/Miscellaneous.h"

void Card::SetMaxStatsFromRarity()
{
	switch (rarity)
	{
		case gold:
			SetMaxStats(4);
			break;
		case purple:
		case blue:
			SetMaxStats(3);
			break;
		case green:
		default:
			SetMaxStats(2);
			break;
	}
}

void Card::SetUnlockedStatsFromLevel()
{
	if (level == 60)
	{
		SetUnlockedStats(4);
	}
	else if (level >= 40 && level < 59)
	{
		SetUnlockedStats(3);
	}
	else if (level <= 20 && level >= 39)
	{
		SetUnlockedStats(2);
	}
	else
	{
		SetUnlockedStats(1);
	}
}

CardConnection& Card::GetCardConnectionFromIndex(int input_index)
{
	return card_connections[input_index];
}

int Card::GetLevel()
{
	return level;
}

int Card::GetMaxCardConnections()
{
	return max_card_connections;
}

int Card::GetMaxStats()
{
	return max_stats;
}

int Card::GetUnlockedStats()
{
	return unlocked_stats;
}

Rarity Card::GetRarity()
{
	return rarity;
}

StatValue& Card::GetStatFromIndex(int input_index)
{
	return stats[input_index];
}

std::string Card::GetName()
{
	return name;
}

void Card::RemoveCardProperties()
{
	level = 0;
	max_card_connections = 0;
	max_stats = 0;
	unlocked_stats = 0;
	rarity = white;
	name = "";
	card_connections.clear();
	stats.clear();
}

void Card::SetLevel(int input_level)
{
	level = input_level;
	SetUnlockedStatsFromLevel();
}

void Card::SetMaxStats(int input_max_stats)
{
	max_stats = input_max_stats;
}

// Precondition: input_stats_unlocked <= max_stats
void Card::SetUnlockedStats(int input_unlocked_stats)
{
	unlocked_stats = input_unlocked_stats;
}

void Card::SetRarity(Rarity input_rarity)
{
	rarity = input_rarity;
	SetMaxStatsFromRarity();
}

void Card::ProcessCardConnectionFile(std::fstream& input_file, int input_index)
{
	std::string connection_name;
	std::string all_connections;
	std::string delimiter = "/";
	std::getline(input_file, connection_name);
	GetCardConnectionFromIndex(input_index).SetName(connection_name);
	std::getline(input_file, all_connections);
	size_t position = 0;
	std::string character_name;

	while ((position = all_connections.find(delimiter)) != std::string::npos) 
{
		int name_index = 0;
		character_name = all_connections.substr(0, position);
		GetCardConnectionFromIndex(input_index);
		all_connections.erase(0, position + delimiter.length());
		name_index++;
	}
}

void Card::InitializeCardConnections()
{
	int line_number = 1;
	std::string file_path = "../../Data Files/Card Connections/";
	std::string extension = ".txt";
	std::string filename = file_path.append(name).append(extension);
	std::fstream input_file;
	input_file.open(filename.c_str());
		GoToLine(input_file, 2);
		line_number = 2;
		input_file >> max_card_connections;
		for (int loop_index = 0; loop_index < max_card_connections; loop_index++)
		{
			ProcessCardConnectionFile(input_file, loop_index);
			line_number += 3;
			GoToLine(input_file, line_number);
		}
	input_file.close();
}