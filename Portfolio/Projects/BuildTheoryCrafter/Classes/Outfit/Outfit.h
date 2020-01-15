// Domenico D'Erasmo
// 20 April 2019
// Interface file for Outfit class

#ifndef OUTFIT_H
#define OUTFIT_H

#include <iostream>

#include "../StatValue/StatValue.h"

class Outfit
{

public:

	Outfit();

	// Accessors
	int GetMaxStats();
	StatValue GetStatFromIndex(int index);
	std::string GetName();
	
	// Mutators
	void SetMaxStats(int input_max_stats);
	void SetName(std::string input_name);
	
	// Operators
	Outfit& operator = (const Outfit& right_outfit);

private:

	int max_stats;
	StatValue stats[3];
	std::string name;

};

#endif // !OUTFIT_H

