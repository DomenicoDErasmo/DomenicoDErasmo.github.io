// Domenico D'Erasmo
// 7 May 2019
// Implementation file for CardConnection class

#include <fstream>
#include <iostream>

#include "CardConnection.h"

bool CardConnection::GetIsActive()
{
	return is_active;
}

double CardConnection::GetMultiplier()
{
	return multiplier;
}

int CardConnection::GetNumberOfCards()
{
	return number_of_cards;
}

std::string CardConnection::GetName()
{
	return name;
}

void CardConnection::PushName(std::string input_name)
{
	required_cards.push_back(input_name);
}

void CardConnection::SetIsActive(bool input_is_active)
{
	is_active = input_is_active;
}

void CardConnection::SetMultiplier(double input_multiplier)
{
	multiplier = input_multiplier;
}

void CardConnection::SetName(std::string input_name)
{
	name = input_name;
}

void CardConnection::SetNumberOfCards(int input_number_of_cards)
{
	number_of_cards = input_number_of_cards;
}
