// Domenico D'Erasmo
// Lab #8
// 3 April 2018

#include <iostream>
#include "Rational.h"

int main() 
{
	// Variables
	char redoCheck;

	// Included because -1 and - have the same first character. If I made the whole conditional block an if-else-if block,
	// 	then this wouldn't be necessary, but then I'd have to prompt for input at every if condition. Both are viable,
	// 	this implementation creates a smaller compiled program while the alternative creates a program that requires
	// 	slightly less memory (one bool variable's worth)
	bool negativeCheck = false;

	std::string operation;
	Rational first(1,1), second (1,1), third(0,1);	// third Rational takes the operations for first and second
	
	std::cout << "Let's start to test operators defined for the Rational class.\n";

	// Input, in a do-while loop to allow for continuous running of the program.
	do
	{
		// Initilaized just to be safe
		redoCheck = 'n';

		// Input
		std::cout << "\nEnter the operator (+, -, *, /, ==, ..., enter -1 for negation) : ";
		std::cin >> operation;

		// This chain of if-else-if deals with the operations with 2 characters
		// Checks for -1
		if (operation == "-1")
		{
			negativeCheck = true;
			std::cout << "Enter the operand (for decimals, include a value before the decimal): ";
			std::cin >> first;
			third = -first;

			// Cleans output, because these can get quite large due to multiplication and decimal conversion
			third.simplify();
			std::cout << "-(" << first << ") = " << third << "\n";
		}

		// Takes input for the rest of the operations, which all take two Rationals
		else
		{
			std::cout << "Enter the operands (for decimals, include a value before the decimal): ";
			std::cin >> first >> second;
		}

		// See line 34
		// Checks for >=
		if (operation == ">=")
		{
			if (first >= second)
			{
				std::cout << first << " >= " << second << " is true.\n";
			}
			else
			{
				std::cout << first << " >= " << second << " is false.\n";
			}
		}

		// See line 34
		// Checks for <=
		else if (operation == "<=")
		{
			if (first <= second)
			{
				std::cout << first << " <= " << second << " is true.\n";
			}
			else
			{
				std::cout << first << " <= " << second << " is false.\n";
			}
		}

		// See line 34
		// Checks for  ==
		else if (operation == "==")
		{
			if (first <= second)
			{
				std::cout << first << " == " << second << " is true.\n";
			}
			else
			{
				std::cout << first << " == " << second << " is false.\n";
			}
		}

		// See line 34
		// Checks for !=
		else if (operation == "!=")
		{
			if (first != second)
			{
				std::cout << first << " != " << second << " is true.\n";
			}
			else
			{
				std::cout << first << " != " << second << " is false.\n";
			}
		}

		// The switch that takes all of the single-character operations
		else
		{
			switch (operation.at(0))
			{

				// Adds the two Rationals
				case '+':
					third = first + second;
					third.simplify();
					std::cout << first << " + " << second << " = " << third << ".\n";
					break;

				// Subtracts the two Rationals
				// Checks that the negation operation wasn't perforemd - see line 17
				case '-':
					if (negativeCheck)
					{
						// Resets negativeCheck for future loops of the program
						negativeCheck = false;
						break;
					}
					else
					{
						third = first - second;
						third.simplify();
						std::cout << first << " - " << second << " = " << third << ".\n";
						break;
					}

				// Multiplies the two Rationals
				case '*':
					third = first * second;
					third.simplify();
					std::cout << first << " * " << second << " = " << third << ".\n";
					break;

				// Divides the two Rationals
				case '/':
					third = first / second;
					third.simplify();
					std::cout << first << " / " << second << " = " << third << ".\n";
					break;

				// Checks if first > second
				case '>':
					if (first > second)
					{
						std::cout << first << " > " << second << " is true.\n";
					}
					else
					{
						std::cout << first << " > " << second << " is false.\n";
					}
					break;

				// Checks if first < second
				case '<':
					if (first < second)
					{
						std::cout << first << " < " << second << " is true.\n";
					}
					else
					{
						std::cout << first << " < " << second << " is false.\n";
					}
					break;
			}
		}

		// Prompts for redo
		std::cout << "Continue? (y/n): ";
		std::cin >> redoCheck;
	}
	while ((redoCheck == 'y') || (redoCheck == 'Y'));
	
	std::cout << "Bye!\n";

	return 0;
}
