// Domenico D'Erasmo
// Lab #7
// 3 April 2018

#include <iostream>
#include "Rational.h"

// function prototypes
void createRationals(Rational*& fractions, int& maxRationals);

int main() 
{
	int loopIndex, maxRationals;

	// variable fractions is a pointer of Rational data type used to dynamically allocate Rationals
	Rational* fractions;

	// Rational variables that also test constructors
	Rational first(3,5, "First");	// first should equal 3/5
	first.output();			// display as 3/5

	Rational second(6);	// second should equal 6/1
	second.output();		// display as 6/1

	Rational third;			// third should equal 0/1
	third.output();			// display as 0/1

	// addBase is the base for adding a series of Rationals
	// multiplyBase is the base for multiplying a series of Rationals
	Rational addBase(0,1,"AddBase");
	Rational multiplyBase(1,1,"MultiplyBase");

	// testing sum function (part of lab 6)
	third.sum(first, second);	// third should equal 33/5
	third.simplify();
	third.output();			// display as 33/5

	// declare two rationals to test input and isEqual functions
	Rational fourth;
	Rational fifth;

	// test input function
	fourth.userInput();
	fifth.userInput();
	
	// test isEqual
	if (fourth.isEqual(fourth, fifth))
	{
		std::cout << fourth.getName() << " and " << fifth.getName() << " are equal.\n";
	}
	else
	{
		std::cout << fourth.getName() << " and " << fifth.getName() << " are not equal.\n";
	}
	
	// add an input set of rational numbers and multiply them
	
	// create Rationals
	createRationals(fractions, maxRationals);
	
	// initialize Rationals with set
	for (loopIndex = 0; loopIndex < maxRationals; loopIndex++)
	{
		fractions[loopIndex].set(1, (loopIndex + 1));
	}
	
	// add the declared Rationals
	for (loopIndex = 0; loopIndex < maxRationals; loopIndex++)
	{
		addBase.sum(addBase, fractions[loopIndex]);
	}
	
	// output (already simplified because Rational.sum calls simplify
	addBase.output();

	// multiply the declared Rationals
	for (loopIndex = 0; loopIndex < maxRationals; loopIndex++)
	{
		multiplyBase.product(multiplyBase, fractions[loopIndex]);
	}

	// output (already simplified because Rational.produce calls simplify);
	multiplyBase.output();
	return 0;
}

// creates and initializes the number of Rationals
void createRationals (Rational*& fractions, int& maxRationals)
{
	// variables
	bool inputCheck = true;

	// create the number of Rationals
	do
	{
		std::cout << "How many rational numbers will be entered? ";
		std::cin >> maxRationals;

		// checks for fewer than 1 rational or for faulty input
		if ((maxRationals < 1) || (std::cin.fail()))
		{
			std::cout << "Invalid data entered. Please try again.\n";
			std::cin.clear();
			std::cin.ignore(100,'\n');
		}	
		else
		{
			fractions = new Rational[maxRationals];
			inputCheck = false;
		}
	}
	while (inputCheck);
}
