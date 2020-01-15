// Domenico D'Erasmo
// 18 April 2019
// Calculator Driver File
// Idea for Refactoring: make driver class with character as member?

#include <iostream>
#include <string>
#include <fstream>

#include "Classes/Character/Character.h"
#include "Classes/Enums/StatCategory/StatCategory.h"
#include "Classes/Trinket/Trinket.h"

void InitializeAccountLevel(Character& character)
{
	int input_account_level;
	std::cout << "Enter the account level: ";
	std::cin >> input_account_level;
	character.SetAccountLevel(input_account_level);
}

void InitializeBaseStats(Character& character)
{
	double stat_value;

	std::cout << "Initializing base stats (note: remove all cards, scenes, and bonus outfit):\n";
	for (int stat_index = 0; stat_index < 13; stat_index++)
	{
		std::cout << "Enter the base stat for " << StatToString((character.GetStatFromIndex(stat_index)).GetCategory()) << ": ";
		std::cin >> stat_value;
		character.GetStatFromIndex(stat_index).SetAmount(stat_value);
	}
}

void InitializeIllustrationBoosts(Character& character)
{
	double stat_value;

	std::cout << "Initializing illustration multipliers (add up all multipliers beforehand):\n";
	for (int stat_index = 0; stat_index < 13; stat_index++)
	{
		std::cout << "Enter the illustration modifier for " << StatToString(character.GetStatFromIndex(stat_index).GetCategory()) << ": ";
		std::cin >> stat_value;
		character.GetIllustrationBoostFromIndex(stat_index).SetAmount(stat_value);
	}
}

void InitializeLevel(Character& character)
{
	int input_level;
	std::cout << "Enter " << character.GetName() << "'s level (Note: This doesn't update level points, you must do that manually): ";
	std::cin >> input_level;
	character.SetLevel(input_level);
}

void InitializeLevelStats(Character& character)
{
	int level_stat_value;

	std::cout << "Initializing level stats (note: don't include scenes): \n";
	for (int stat_index = 0; stat_index < 6; stat_index++)
	{
		std::cout << "Enter the base stat for " << StatToString(character.GetLevelStatFromIndex(stat_index).GetCategory()) << ": ";
		std::cin >> level_stat_value;
	}
}

void InitializeName(Character& character)
{
	std::string input_name;
	std::cout << "Enter the character's name: ";
	std::cin >> input_name;
	character.SetName(input_name);
}

void InitializeOutfit(Character& character)
{
	// Outfit input_outfit;
	double amount;
	int max_stats;
	std::string name;
	std::cout << "Enter the outfit name (consult OutfitList.txt): ";
	std::cin >> name;
	std::cout << "Enter the number of stats: ";
	std::cin >> max_stats;
	character.GetOutfit().SetMaxStats(max_stats);
	character.GetOutfit().SetName(name);
	for (int stat_index = 0; stat_index < max_stats; stat_index++)
	{
		
		std::cout << "Enter stat " << stat_index + 1 << "'s type: ";
		std::cin >> name;
		std::cout << "Enter the stat's value: ";
		std::cin >> amount;
		character.GetOutfit().GetStatFromIndex(stat_index).SetAmount(amount);
	}
	std::cout << character.GetOutfit().GetName() << std::endl;
}

void InitializeTrinkets(Character& character)
{
	int level;

	std::cout << "Initializing trinkets...\n";
	
	for (int stat_index = 0; stat_index < 3; stat_index++)
	{
		std::cout << "Enter the " << stat_index + 1 << "th trinket level: ";
		std::cin >> level;
		character.GetTrinketFromIndex(stat_index).SetLevel(level);
	}
}

void InitializeUSBLevel(Character& character)
{
	int usb_level;
	std::cout << "Enter the new USB Level: ";
	std::cin >> usb_level;
	character.SetUSBLevel(usb_level);
}

void InitializeCharacter(Character& character)
{
	std::cout << "Now initializing character (note: remove all cards, scenes, and bonus outfit)...\n";
	
	InitializeAccountLevel(character);
	InitializeName(character);
	character.InitializeStatCategories();
}

void DisplayAccountLevel(Character& character)
{
	char yes_no;
	std::cout << "Account level: " << character.GetAccountLevel() << "\n";
	std::cout << "Do you want to change the account level (y/n)?";
	std::cin >> yes_no;
	if (yes_no == 'y')
	{
		InitializeAccountLevel(character);
	}
}

void DisplayBaseStats(Character& character)
{
	char yes_no;
	std::cout << "Base Stats:\n";
	for (int stat_index = 0; stat_index < 13; stat_index++)
	{
		std::cout << StatToString((character.GetStatFromIndex(stat_index)).GetCategory()) << " - " << character.GetBaseStatFromIndex(stat_index).GetAmount() << "\n";
	}

	std::cout << "Do you want to change the base stats (y/n)?";
	std::cin >> yes_no;
	if (yes_no == 'y')
	{
		InitializeBaseStats(character);
	}
}

void DisplayAllCardsBriefly(Character& character)
{
	for (int card_index = 0; card_index < character.GetNumberOfEquippedCards(); card_index++)
	{
		std::cout << "[" << card_index << "] - " << character.GetCardFromIndex(card_index).GetName() << " - " << RarityToString(character.GetCardFromIndex(card_index).GetRarity());
	}
}

void DisplaySpecificCardInDetail(Character& character)
{
	int card_index;
	std::cout << "Enter a number to display a card in full detail: ";
	std::cin >> card_index;
	std::cout << "Name: " << character.GetCardFromIndex(card_index).GetName() << " (Rarity " << character.GetCardFromIndex(card_index).GetRarity() << ") \n";
	std::cout << "Level: " << character.GetCardFromIndex(card_index).GetLevel() << " \n";
	for (int stat_index = 0; stat_index < character.GetCardFromIndex(card_index).GetMaxStats(); stat_index++)
	{
		std::cout << StatToString(character.GetCardFromIndex(card_index).GetStatFromIndex(stat_index).GetCategory()) << ": " << std::to_string(character.GetCardFromIndex(card_index).GetStatFromIndex(stat_index).GetAmount()) << "\n";
	}
}

int PromptCardToRemove()
{
	int cardIndex;
	std::cout << "Enter the index of the card to remove: ";
	std::cin >> cardIndex;
}

void RemoveCard(Character& character)
{
	character.GetCardFromIndex(PromptCardToRemove()).RemoveCardProperties();
	character.SetNumberOfEquippedCards(character.GetNumberOfEquippedCards() - 1);
}

std::string PromptName()
{
	std::string input_name;
	std::cout << "Enter the card's name: ";
	std::cin >> input_name;
	return input_name;
}

std::string GetCardFilePath(std::string input_name)
{
	std::string file_path = "../../Data Files/Cards/";
	std::string extension = ".txt";
	std::string filename = file_path.append(input_name).append(extension);
	return filename;
}

void AddCard(Character& character)
{
	// Add by name, ID number
	std::fstream file;
	file.open(GetCardFilePath(PromptName()));
		
	file.close();
	
}

// TODO: Flesh out
void DisplayCards(Character& character)
{
	char card_action;
	DisplayAllCardsBriefly(character);
	std::cout << "Do you want to [d] display a specific card, [r] remove a card, or [a] add a card? ";
	std::cin >> card_action;
	if (card_action == 'd')
	{
		DisplaySpecificCardInDetail(character);
	}
	else if (card_action == 'r')
	{
		RemoveCard(character);
	}
	else
	{
		AddCard(character);
	}
}

void DisplayIllustrationBoosts(Character& character)
{
	char yes_no;
	std::cout << "Illustration Boosts:\n";
	for (int stat_index = 0; stat_index < 13; stat_index++)
	{
		std::cout << StatToString(character.GetIllustrationBoostFromIndex(stat_index).GetCategory()) << " - " << character.GetIllustrationBoostFromIndex(stat_index).GetAmount() << "\n";
	}

	std::cout << "Do you want to change the base stats (y/n)?";
	std::cin >> yes_no;
	if (yes_no == 'y')
	{
		InitializeBaseStats(character);
	}
}

void DisplayLevel(Character& character)
{
	char yes_no;
	std::cout << "Character level: " << character.GetLevel() << "\n";
	std::cout << "Do you want to change the character level (y/n)?";
	std::cin >> yes_no;
	if (yes_no == 'y')
	{
		InitializeLevel(character);
	}
}

void DisplayLevelStats(Character& character)
{
	char yes_no;
	std::cout << "Base Stats:\n";
	for (int stat_index = 0; stat_index < 5; stat_index++)
	{
		std::cout << StatToString(character.GetLevelStatFromIndex(stat_index).GetCategory()) << " - " << character.GetLevelStatFromIndex(stat_index).GetAmount() << "\n";
	}

	std::cout << "Do you want to change the level stats (y/n)?";
	std::cin >> yes_no;
	if (yes_no == 'y')
	{
		InitializeLevelStats(character);
	}
}

void DisplayOutfit(Character& character)
{
	char yes_no;
	std::cout << "Outfit: " << character.GetOutfit().GetName() << "\n";
	std::cout << "Do you want to change the outfit (y/n)?";
	std::cin >> yes_no;
	if (yes_no == 'y')
	{
		InitializeOutfit(character);
	}
}

void DisplayStats(Character& character)
{
	std::cout << "Stats:\n";
	for (int stat_index = 0; stat_index < 13; stat_index++)
	{
		std::cout << StatToString((character.GetStatFromIndex(stat_index)).GetCategory()) << " - " << character.GetStatFromIndex(stat_index).GetAmount() << "\n";
	}
}

void DisplayTrinkets(Character& character)
{
	char yes_no;
	std::cout << "Trinkets:\n";

	for (int stat_index = 0; stat_index < 3; stat_index++)
	{
		std::cout << StatToString(character.GetTrinketFromIndex(stat_index).GetStat().GetCategory()) << " - " << character.GetTrinketFromIndex(stat_index).GetLevel() << "\n";
	}
	
	std::cout << "Do you want to change the base stats (y/n)?";
	std::cin >> yes_no;
	if (yes_no == 'y')
	{
		InitializeTrinkets(character);
	}
}

void DisplayUSBLevel(Character& character)
{
	char yes_no;
	std::cout << "USB Level: " << character.GetUSBLevel() << "\n";
	std::cout << "Do you want to change the USB level (y/n)?";
	std::cin >> yes_no;
	if (yes_no == 'y')
	{
		InitializeUSBLevel(character);
	}
}

char DisplayMenu(Character& character)
{
	char menu_flow;

	std::cout << character.GetName() << "\n";
	std::cout << "0 - View Level            " << "1 - View Account Level    " << "2 - View Outfit           " << "3 - View Trinkets         \n";
	std::cout << "4 - View Base Stats       " << "5 - View Stats            " << "6 - View Level Stats      " << "7 - View Illustartion Mods\n";
	std::cout << "8 - View Cards            " << "9 - View Scenes           " << "A - View USB Level        " << "B - Exit                  \n";
	std::cout << "Enter a character corresponding to the data you want to modify: ";
	
	std::cin >> menu_flow;
	return menu_flow;
}

char PrintMenu(Character& character)
{
	char menu_flow = DisplayMenu(character);
	
	switch (menu_flow)
	{
	case '0':
		DisplayLevel(character);
		break;
	case '1':
		DisplayAccountLevel(character);
		break;
	case '2':
		DisplayOutfit(character);
		break;
	case '3':
		DisplayTrinkets(character);
		break;
	case '4':
		DisplayBaseStats(character);
		break;
	case '5':
		DisplayStats(character);
		break;
	case '6':
		DisplayLevelStats(character);
		break;
	case '7':
		DisplayIllustrationBoosts(character);
		break;
	case '8':
		DisplayCards(character);

	case '9':
	case 'A':
		DisplayUSBLevel(character);
	case 'B':
		break;
	default:
		menu_flow = 'B';
		break;
	};

	return menu_flow;
}

int main()
{
	Character character;
	InitializeCharacter(character);
	while (true)
	{
		if (PrintMenu(character) == 'B')
		{
			break;
		}

	}

	return 0;
}