// Domenico D'Erasmo
// 18 April 2019
// Implementation file for Stat class

#include <iostream>

#include "StatValue.h"
#include "../Enums/StatCategory/StatCategory.h"

StatValue::StatValue()
{
	amount = 0;
	category = health;
}

double StatValue::GetAmount()
{
	return amount;
}

StatCategory StatValue::GetCategory()
{
	return category;
}

void StatValue::SetAmount(double input_amount)
{
	amount = input_amount;
}

void StatValue::SetCategory(StatCategory input_category)
{
	category = input_category;
}

StatValue& StatValue::operator = (const StatValue& right_stat_value)
{
	amount = right_stat_value.amount;
	category = right_stat_value.category;
	return *this;
}

// Precondition: both StatValues have the same StatCategory
StatValue& StatValue::operator + (const StatValue& right_stat_value)
{
	amount = amount + right_stat_value.amount;
	return *this;
}

StatValue& StatValue::operator * (double multiplier)
{
	amount = amount * multiplier;
	return *this;
}
