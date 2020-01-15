// Domenico D'Erasmo
// 19 April 2019
// Interface file for Trinket class

#ifndef TRINKET_H
#define TRINKET_H

#include <iostream>

#include "../StatValue/StatValue.h"

class Trinket
{

public:

	Trinket();

	// Accessors
	int GetLevel();
	int GetMaxLevel();
	StatValue GetStat();

	// Mutators
	void SetLevel(int input_level);
	void SetMaxLevel(int account_level);
	void SetStatCategory(StatCategory input_category);

private:

	int level;
	int max_level;
	StatValue stat;

};

#endif // !TRINKET_H
