#include <iostream>
#include "Rational.h"

Rational::Rational (int numeratorInput, int denominatorInput, std::string nameInput)
{
	numerator = numeratorInput;
	denominator = denominatorInput;
	name = nameInput;
}

// uses input to create denominator
void Rational::userInput()
{

	// variables to check for acceptable input values
	int numeratorInput, denominatorInput;
	bool numInputCheck = true, denomInputCheck = true;

	// check for numerator (junk values)

	do
	{
		std::cout << "Enter the rational number's numerator : ";
		std::cin >> numeratorInput;
		if (std::cin.fail())                                    // checks for invalid input
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			std::cout << "Invalid numerator entered. Please try again.\n";
		}
		else
		{
			numerator = numeratorInput;
			numInputCheck = false;
		}
	}
	while (numInputCheck);
			
	// check for denominator (junk values and != 0)
	do
	{
		std::cout << "Enter the rational number's denominator : ";
		std::cin >> denominatorInput;
		if ((std::cin.fail()) || (denominatorInput == 0))       // checks for invalid input
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			std::cout << "Invalid denominator entered. Please try agian.\n";
		}
		else
		{
			denominator = denominatorInput;
			denomInputCheck = false;
		}
	}
	while (denomInputCheck);

	// prompts for name, no filter because the name is a string
	std::cout << "Enter the rational number's name : ";
	std::cin >> name;
}

// creates output
void Rational::output()
{
	std::cout << "Rational number " << name << " is " << numerator << "/" << denominator << "\n";
}

// accesses numerator
int Rational::getNumerator()
{
	return numerator;
}

// accesses denominator
int Rational::getDenominator()
{
	return denominator;
}

// accesses rational number name
std::string Rational::getName()
{
	return name;			
}

// makes the fraction equal to the sum of the two fractions given as arguments, redundantly used accessor functions to verify that they work
void Rational::sum (const Rational& first, const Rational& second)
{
	numerator = ((first.numerator * second.denominator) + (first.denominator * second.numerator));
	denominator = (first.denominator * second.denominator);
	simplify();
}

// checks if the two fractions are equal, through these three steps:
	//	1. cast the numerators and denominators as doubles
	//	2. divide numerators by denominators
	//	3. check if the values are within a relative threshhold of error
bool Rational::isEqual (const Rational& first, const Rational& second)
{
	// variables for steps 1 and 2
	double firstRational = double(first.numerator) / double(first.denominator);
	double secondRational = double(second.numerator) / double (second.denominator);

	// error factor used in step 3
	double errorFactor = 0.0001;

	// compare values for step 3, works if first > second and if second < first
	if (((firstRational - secondRational) <= errorFactor * firstRational) && ((firstRational - secondRational) >= (-1 * errorFactor * firstRational)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// modifies the numerator and denominator using three parameters:
	//	1. int numeratorInput - sets numerator to this value
	//	2. int denominatorInput - sets denominator to this value
	//	3. Rational& input - calls Rational by input to change its values
void Rational::set (int numeratorInput, int denominatorInput)
{
	if (denominatorInput == 0)
	{
		std::cout << "The values couldn't be written: Denominator equaled zero.\n";
		return;
	}
	else
	{
		denominator = denominatorInput;
		numerator = numeratorInput;
	}
	simplify();
}

// makes the rational number equal to the product of the two rational numbers given as arguments
void Rational::product (const Rational& first, const Rational& second)
{
	numerator = first.numerator * second.numerator;
	denominator = first.denominator * second.denominator;
	simplify();
}

// simplifies the rational number using greatest common factor
void Rational::simplify()
{
	int loopIndex, factor = 1;
	for (loopIndex = 1; loopIndex < denominator; loopIndex++)
	{
		if ((denominator % loopIndex == 0) && (numerator % loopIndex == 0))
		{
			factor = factor * loopIndex;
		}
	}
	numerator = numerator / factor;
	denominator = denominator / factor;
}

