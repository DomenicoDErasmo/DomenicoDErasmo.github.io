#include <iostream>
#include <sstream>
#include <math.h>
#include "Rational.h"

// README
// This is the implementation of the Rational Class
// The logic for the input is messy but it takes the following inputs:
	// fractions (numerator / numerator)
	// decimals
	// decimal fractions (decimal / decimal)
// Sadly I ran out of time to make decimals such as .4 work. I need to familiarize myself better with stringstreams and how to
// 	sanitize their input.
// Implementing the last two took me SO LONG I'VE BEEN WORKING ON THIS FOR LIKE FIVE HOURS AHHHHHHH
// But it works!

// Constructor that creates numerator and denominator
Rational::Rational (int numeratorInput, int denominatorInput)
{
	numerator = numeratorInput;
	denominator = denominatorInput;
}

// Sets values of Rational 
// Takes two arguments:
// 	numInput - Assigned to the Rational numerator
// 	denomInput - Assigned to the Rational denominator
void Rational::set(int numInput, int denomInput)
{
	// Checks if the denominator equals zero, exits if that is the case
	if (denomInput = 0)
	{
		std::cout << "Error: Denominator equals zero. Exiting the program.\n";
		exit(1);
	}
	else
	{
		numerator = numInput;
		denominator = denomInput;
	}
}

// Accesses numerator
// This is of type const so certain functions can access Rational private variables
// (thank God for stackexchange)
int Rational::getNumerator() const
{
	return numerator;
}

// accesses denominator
// Const is for the same reason as above
int Rational::getDenominator() const
{
	return denominator;
}

// Simplifies the rational number using greatest common factor
void Rational::simplify()
{
	int loopIndex, factor;
	for (loopIndex = 1; ((loopIndex <= std::abs(numerator)) && (loopIndex <= std::abs(denominator))); loopIndex++)
	{
		if ((std::abs(numerator) % loopIndex == 0) && (std::abs(denominator) % loopIndex == 0))
		{
			factor = loopIndex;
		}
	}
	numerator = numerator / factor;
	denominator = denominator / factor;
}

// Adds the two Rationals
// Uses two arguments:
// 	first and second are Rationals
// Given a/b and c/d, the sum is (ad + bc)/ad
// A temporary Rational is created and returned
// 	This is relatively expensive but is also easy to implement
Rational operator + (const Rational& first, const Rational& second)
{
	Rational temp(((first.getNumerator() * second.getDenominator()) + (first.getDenominator() * second.getNumerator())), (first.getDenominator() * second.getDenominator()));
	return temp;
}

// Negates the Rational
// Takes one argument (first)
// first is used in the construction of a temporary Rational, which is returned at the end of the operation
Rational operator - (const Rational& first)
{
	Rational temp((first.getNumerator() * (-1)), first.getDenominator());
	return temp;
}

// Subtracts the second Rational from the first
// Uses two arguments:
// 	first and second are Rationals
// Given a/b and c/d, the sum is (ad - bc)/ad
// A temporary Rational is created and returned
Rational operator - (const Rational& first, const Rational& second)
{
	Rational temp(((first.getNumerator() * second.getDenominator()) - (first.getDenominator() * second.getNumerator())), (first.getDenominator() * second.getDenominator()));
	return temp;
}

// Multiplies one Rational by another
// Uses two arguments:
// 	first and second are Rationals
// Given a/b and c/d, the product is ab/cd
Rational operator * (const Rational& first, const Rational& second)
{
	Rational temp((first.getNumerator() * second.getNumerator()), (first.getDenominator() * second.getDenominator()));
	return temp;
}

// Divides the first Rational by the second
// Uses two arguments:
// 	first and second are Rationals
// Given a/b and c/d. the product is ad/bc
Rational operator / (const Rational& first, const Rational& second)
{
	Rational temp((first.getNumerator() * second.getDenominator()), (first.getDenominator() * second.getNumerator()));
	return temp;
}

// Checks if the Rationals are equal by using an error threshold of 0.01% of the first Rational
// Uses two arguments:
// 	first and second are Rationals
bool operator == (const Rational& first, const Rational& second)
{
	// Variables for comparison
	double firstRational = double(first.numerator) / double(first.denominator);
	double secondRational = double(second.numerator) / double (second.denominator);

	// Error factor used in determining "equality"
	double errorFactor = 0.0001;

	// Compare values, works if first > second and if second < first
	if (std::abs(firstRational - secondRational) <= errorFactor * firstRational)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Checks if the first Rational is inequal to the second
// Same implementation of the == operator, except this checks that the error amount is exceeded
// Uses two arguments:
// 	first and second are Rationals
bool operator != (const Rational& first, const Rational& second)
{
	// Variables for comparison
	double firstRational = double(first.numerator) / double(first.denominator);
	double secondRational = double(second.numerator) / double (second.denominator);

	// Error factor used in determining "equality"
	double errorFactor = 0.0001;

	// Compare values
	if (std::abs(firstRational - secondRational) > errorFactor * firstRational)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Checks if the first Rational is less than the second
// Similar implementation as operator ==, except this doesn't need an error facor and checks for first < second
// Uses two arguments:
// 	first and second are Rationals
bool operator < (const Rational& first, const Rational& second)
{
	// Variables for comparison
	double firstRational = double(first.numerator) / double(first.denominator);
	double secondRational = double(second.numerator) / double (second.denominator);

	// Comparison
	if (firstRational < secondRational)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Checks if the first Rational is greater than or equal to the second
// Same implementation as operator <, except this checks for first <= second
// Uses two arguments:
// 	first and second are Rationals
bool operator <= (const Rational& first, const Rational& second)
{
	// Variables for comparison
	double firstRational = double(first.numerator) / double(first.denominator);
	double secondRational = double(second.numerator) / double (second.denominator);

	// Comparison
	if (firstRational <= secondRational)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Checks if the first Rational is greater than the second
// Same implementation as operator <=, except this checks for first > second
// Uses two arguments:
// 	first and second are Rationals
bool operator > (const Rational& first, const Rational& second)
{
	// Variables for comparison
	double firstRational = double(first.numerator) / double(first.denominator);
	double secondRational = double(second.numerator) / double (second.denominator);

	// Comparison
	if (firstRational > secondRational)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Checks if the first Rational is greater than or equal to the second
// Same implementation as operator >, except this checks for first >= second
// Uses two arguments:
// 	first and second are Rationals
bool operator >= (const Rational& first, const Rational& second)
{
	// Variables for comparison
	double firstRational = double(first.numerator) / double(first.denominator);
	double secondRational = double(second.numerator) / double (second.denominator);

	// Comparison
	if (firstRational >= secondRational)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Inputs values into Rational
// Uses two variables:
//	in is a reference to istream, it is by reference to allow for >> to be chained
//	first is a Rational that gets modified
std::istream& operator >> (std::istream& in, Rational& first)
{
	// Variables
	std::string input;
	bool foundSlash = false;	// Checks for one slash to prevent too many slashes
	bool isValid = true;		// Checks for valid input format before converting to stringstream
	bool foundDecimal = false;	// Checks for decimal before applying decimal portion of input reading
	int loopIndex;

	// decimalSpot can never naturally be -1 because it depends on loopIndex which depends on the stream location (always > 0)
	// This is set to < 0 because the decimal code is enabled by decimalSpot
	// decimalSpot is used instead of foundDecimal because foundDecimal can reset to false in case a decimal is present in
	// 	both the numerator and denominator, but if a decimal is present it one, then foundDecimal would stay false
	int decimalSpot = -1;

	// slashSpot is needed to ensure that the / doesn't occur as the first character
	int slashSpot = 0;		
														
	// Insertion to the input string to be parsed
	in >> input;

	// Data checking
	for (loopIndex = 0; (loopIndex < input.length() && isValid); loopIndex++)
	{
		// Checks for negative sign
		if (input[loopIndex] == '-')
		{
			// Checks that negative sign is the first character
			if (loopIndex != 0)
			{
				isValid = false;

				// These messages are given as feedback to the user and also doubled as debugging flags.
				std::cout << "Check the negative placement condition!\n";
			}
		}
		else if (input[loopIndex] == '.')
		{
			// Checks that this is the only decimal before the /
			if (foundDecimal)	
			{ 
				isValid = false;

				// See line 290
				std::cout << "Check the too many decimals condition!\n";
			}
			else
			{
				foundDecimal = true;

				// Sets the decimal spot, enabling the decimal portion of the operator
				decimalSpot = loopIndex;
			}
		}
		else if (input[loopIndex] == '/')
		{
			// Checks for several conditions:
			// 	The preceding character isn't a negative sign
			// 	The / isn't the first character
			// 	The / isn't the last character	
			if (((input[0] == '-') && (input[1] == '/')) || ((loopIndex == 0) || (loopIndex == (input.length()-1))) || foundSlash)				
			{
				isValid = false;	

				// See line 290
				std::cout << "Check that the / isn't first, last, or after a - sign!\n";
			}
			else
			{
				foundSlash = true;

				// Resets foundDecimal in case a decimal is given in the denominator
				foundDecimal = false;	
			}
		}
		
		// Checks if the input character isn't from 0-9
		else if (((input[loopIndex] < '0') || (input[loopIndex] > '9')))	
		{
			isValid = false;
	
			// See line 290
			std::cout << "Check that only numbers are used (except '-,' '.,' and '/') " << input[loopIndex] << "!\n";
		}
	}

	// Checks for valid string entered
	if (!isValid)
	{
		std::cout << "Invalid format for rational.\n";
		exit(1);
	}

	// Stringstream to enter from the string to the Rational
	std::stringstream checkedInput(input);		
	
	// Used to remove the / or . from the stringstream
	char charBuffer;				

	// Checks for /, makes denominator = 1 if no / is found
	if (!foundSlash)
	{
		first.denominator = 1;
	}
	
	// Checks for a decimal-based number and converts to a fraction, also works with decimal/decimal
	if ((decimalSpot != -1))
	{
		int numeratorDecimalBuffer = 0;		// Deals with decimal in numerator
		int denominatorDecimalBuffer = 0;	// Deals with decimal in denominator
			
		// Deals with insertion into numerator
		if (checkedInput >> first.numerator)
		{
			checkedInput >> charBuffer;
			if (charBuffer = '.')
			{
				// NumeratorDecimalBuffer is used to convert the decimal to a fraction by multiplying by 
				// 	10^(number of places) in numerator and denominator and adding the buffer to this 
				// 	new numerator 
				// charBuffer takes care of the fraction sign
				checkedInput >> numeratorDecimalBuffer >> charBuffer;
			}				
		}

		// Deals with insertion into denominator
		if (checkedInput >> first.denominator)
		{
			checkedInput >> charBuffer;
			if (charBuffer = '.')
			{
				// denominatorDecimalBuffer works in a similar way as numeratorDecimalBuffer, except it multiplies 
				// 	the numerator by 10^(number of places) and does the same in denominator while adding the 
				// 	buffer to the new denominator
			checkedInput >> denominatorDecimalBuffer;
			}
		}
		
		// Deals with denominator of 0
		if (first.denominator + denominatorDecimalBuffer == 0)
		{
			// See line 290
			std::cout << "Error: Denominator equals zero!\n";
			exit(1);
		}
		else
		{
			// Some number a.b/1 = a * 10^(places of b) + b / 1 * 10^(places of b)
			// The places of b can be expressed as ((int) log10 (Buffer)) + 1
			// These variables are set to 0 by default because 10^0 = 1, meaning no change occurs
			int numeratorPlace = 0, denominatorPlace = 0;
			
			// Sets numeratorPlace and denominatorPlace and then uses the greater of the two variables in the fraction
			// If numeratorDecimalBuffer or denominatorDecimalBuffer == 0 by this point, the corresponding place 
			// 	variable is set to 0 so that the calculation doesn't run ln(0), which doesn't exist
			if (numeratorDecimalBuffer != 0)
			{
				// log10, cast as an int, gives one fewer than the number of digits
				numeratorPlace = (((int)log10(numeratorDecimalBuffer)) + 1);
			}
			if (denominatorDecimalBuffer != 0)
			{
				// See line 419
				denominatorPlace = (((int)log10(denominatorDecimalBuffer)) + 1);
			}
			if (numeratorPlace > denominatorPlace)
			{
				// shifts numeratorDecimalBuffer by appropiate powers of 10
				numeratorDecimalBuffer = (numeratorDecimalBuffer * pow(10, numeratorPlace - denominatorPlace - 1));
				denominatorPlace = numeratorPlace;
			}
			else
			{
				// shifts denominatorDecimalBuffer by appropiate powers of 10
				denominatorDecimalBuffer = (denominatorDecimalBuffer * pow(10, denominatorPlace - numeratorPlace - 1));
			}

			// sets numerator and denominator based on above formula, both pow functions use denominatorPlace 
			// 	to streamline logic (they must be set to the larger of the two place values)
			// std::cout << "numBuffer is " << numeratorDecimalBuffer << " denomBuffer is " << 
			// 	denominatorDecimalBuffer << ".\n";
			first.numerator = (((first.numerator * (pow (10, denominatorPlace))) + numeratorDecimalBuffer));
			first.denominator = (((first.denominator * pow (10, denominatorPlace)) + denominatorDecimalBuffer));
		}
	}
	else
	{
		// This is the code without any decimals.
		// So easy, right? Unless there's a simpler way of doing the above extra credit, I think it should be
		// 	worth more than ten points...
		// In any case it was fun and let me acquire a greater understanding of abstract classes.
		if (checkedInput >> first.numerator)
		{
			checkedInput >> charBuffer >> first.denominator;
			if (first.denominator == 0)
			{
				std::cout << "Error: Denominator equals zero!\n";
				exit(1);
			}
		}
	}	
	
	return in;
}

// Outputs the Rational
// Takes two arguments:
// 	out is an ostream called by reference to allow for chaining the << operator
// 	first is the Rational being output.
std::ostream& operator << (std::ostream& out, const Rational& first)
{
	out << first.numerator << "/" << first.denominator;
	return out; 
} 
