// Domenico D'Erasmo
// 7 May 2019
// Interface file for CardConnection class

#ifndef CARDCONNECTION_H
#define CARDCONNECTION_H

#include <iostream>
#include <vector>

class CardConnection
{

public:

	// Accessors
	bool GetIsActive();
	double GetMultiplier();
	int GetNumberOfCards();
	std::string GetName();

	// Mutators
	void PushName(std::string input_name);
	void SetIsActive(bool input_is_active);
	void SetMultiplier(double input_multiplier);
	void SetName(std::string input_name);
	void SetNumberOfCards(int input_number_of_cards);

private:

	bool is_active;
	double multiplier;
	int number_of_cards;
	std::vector<std::string> required_cards;
	std::string name;

};

#endif // !CARDCONNECTION_H
