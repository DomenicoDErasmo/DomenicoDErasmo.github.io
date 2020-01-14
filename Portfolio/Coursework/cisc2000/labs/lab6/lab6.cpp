// Domenico D'Erasmo
// Lab #6
// 21 March 2018

#include <iostream>

// Rational number class
// Rational numbers can be expressed as numerator/denominator
// This class has three data types, all of which are private members of the class :
// 	1. numerator: the numerator of the rational number
// 	2. denominator: the denominator of the rational number
// 	3. name: the name of the rational number
// 		Note: name was not originally part of the lab. I added it in to make the output more 
// 		presentable, so that the user would know which rational number is being referred to.
// This class has three constructors, all of which are public members of the class :
// 	1. The default constructor (gives name "Default", numerator = 0, and denominator = 1)
// 	2. The numerator constructor (gives input name, input numerator, and denominator = 1)
// 	3. The complete constructor (gives input name, numerator, and denominator)
// This class has several functions, all of which are public memebrs of the class :
// 	1. userInput - prompts user for input for the rational number's data values
// 	2. output - provides user with output, identifying the output rational number and expressing it in numerator/denominator form
// 	3. getNumerator - gets numerator so it can be accessed publicly
// 	4. getDenominator - gets denominator so it can be accessed publicly
// 	5. getName - gets name so it can be accessed publicly
// 	6. sum - makes a rational number equal to two other fractions
// 	7. isEqual - checks if the two given rational numbers are equal by comparing them to an error margin of 0.01%
//
class Rational 
{
	public:
		// default constructor, sets to 0/1
		Rational()
		{
			numerator = 0;
			denominator = 1;
			name = "Default";
		};

		// creates a rational number with form numerator/1
		// numeratorInput is assgined as the numerator of the rational number
		// name is assigned as the name of the rational number
		Rational (int numeratorInput, std::string nameInput)
		{
			numerator = numeratorInput;
			denominator = 1;
			name = nameInput;
		};

		// creates a rational number with form numerator/denominator
		// numeratorInput is assigned to the numerator of the rational number
		// denominatorInput is assigned to the denominator of the rational number
		// nameInput is assigned to the name of the rational number
		Rational (int numeratorInput, int denominatorInput, std::string nameInput)
		{
			numerator = numeratorInput;
			denominator = denominatorInput;
			name = nameInput;
		};

		// uses input to create denominator
		void userInput()
		{
			// variables to check for acceptable input values
			int numeratorInput, denominatorInput;
			bool numInputCheck = true, denomInputCheck = true;

			// check for numerator (junk values)
			do
			{
				std::cout << "Enter the rational number's numerator : ";
				std::cin >> numeratorInput;
				if (std::cin.fail())					// checks for invalid input
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
				if ((std::cin.fail()) || (denominatorInput == 0))	// checks for invalid input
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
		};

		// creates output
		void output()
		{
			std::cout << "Rational number " << name << " is " << numerator << "/" << denominator << "\n";
		};

		// accesses numerator
		int getNumerator() 
		{
			return numerator;
		};

		// accesses denominator
		int getDenominator()
		{
			return denominator;
		};
	
		// accesses rational number name
		std::string getName()
		{
			return name;
		};

		// makes the fraction equal to the sum of the two fractions given as arguments, redundantly used accessor functions to verify that they work
		void sum (Rational first, Rational second)
		{	
			numerator = ((first.getNumerator() * second.getDenominator()) + (first.getDenominator() * second.getNumerator()));
			denominator = first.getDenominator() * second.getDenominator();
		};

		// checks if the two fractions are equal, through these three steps:
		// 	1. cast the numerators and denominators as doubles
		// 	2. divide numerators by denominators
		// 	3. check if the values are within a relative threshhold of error
		bool isEqual (Rational first, Rational second)
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
		};

	private:
		// parameters to be used by functions
		int numerator;
		int denominator;
		std::string name;
};

int main() 
{
	//testing constructors
	Rational first(3,5, "First");	// first should equal 3/5
	first.output();			// display as 3/5

	Rational second(6, "Second");	// second should equal 6/1
	second.output();		// display as 6/1

	Rational third;			// third should equal 0/1
	third.output();			// display as 0/1

	// testing sum function
	third.sum(first, second);	// third should equal 33/5
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
	
	return 0;
}
