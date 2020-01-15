// Domenico D'Erasmo
// 30 December 2018
// Interface file for Stat class

#ifndef STATVALUE_H
#define STATVALUE_H

#include "../Enums/StatCategory/StatCategory.h"

class StatValue
{

public:

	// Constructors
	StatValue();

	// Accessors
	double GetAmount();
	StatCategory GetCategory();

	// Mutators
	void SetAmount(double input_value);
	void SetCategory(StatCategory input_category);

	// Operators
	StatValue& operator = (const StatValue& right_stat_value);
	StatValue& operator + (const StatValue& right_stat_value);
	StatValue& operator * (double multiplier);

private:

	double amount;
	StatCategory category;

};

#endif
#pragma once
