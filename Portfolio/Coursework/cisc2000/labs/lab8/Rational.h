// Domenico D'Erasmo
// Lab #7
// 3 April 2018

#include <iostream>

// Rational number class
// Rational numbers can be expressed as numerator/denominator
// This class has two data types, which are private members of the class :
//      1. numerator: the numerator of the rational number
//      2. denominator: the denominator of the rational number
// This class has one constructor, which is a public member of the class:
//      Rational (int numerator = 0, int denominator = 1)
// This class has several functions, all of which are public memebrs of the class :
//      1. userInput - prompts user for input for the rational number's data values
//      2. output - provides user with output, identifying the output rational number and expressing it in numerator/denominator form
//      3. getNumerator - gets numerator so it can be accessed publicly
//      4. getDenominator - gets denominator so it can be accessed publicly
//      5. sum - makes a rational number equal to two other fractions
//      6. isEqual - checks if the two given rational numbers are equal by comparing them to an error margin of 0.01% of the first value
// This class has overloaded operators for all of the following:
// 	1. Arithmetic Operators (+, -, *, /)
// 	2. Boolean Operators (==, !=, <, <=, >, >=)
// 	3. I/O Operators (>>, <<)

class Rational
{
	public:
	
		// creates a rational number with form numerator/denominator
		// numeratorInput is assigned to the numerator of the rational number or to 0 by default
		// denominatorInput is assigned to the denominator of the rational number or to 1 by default
		// nameInput is assigned to the name of the rational number
		Rational (int numeratorInput = 0, int denominatorInput = 1);
		
		// uses input numbers to change numerator and denominator of Rational
		void set(int num, int denom);

		// accesses numerator
		int getNumerator() const;
		
		// accesses denominator
		int getDenominator() const;
		
		// simplifies the rational number using greatest common factor
		void simplify();
	
	// arithmetic operators

		// Adds the two rationals together
		// Takes two Rationals (first and second) to be added
		// Returns a Rational
		friend Rational operator + (const Rational& first, const Rational& second);

		// Negates the rational
		// Multiplies the Rational by -1
		// Returns a Rational
		// Doesn't use const to modify the Rational
		// While would normally be redundant, I want an argument to overload -
		friend Rational operator - (const Rational& first);

		// Subtracts one Rational from another
		// Takes two Rationals (first and second)
		// Returns a Rational
		friend Rational operator - (const Rational& first, const Rational& second);

		// Multiplies the two rationals
		// Takes two Rationals (first and second)
		// Returns a Rational
		friend Rational operator * (const Rational& first, const Rational& second);

		// Divides the first Rational by the Second
		// Takes two Rationals (first and second)
		// Returns a Rational
		friend Rational operator / (const Rational& first, const Rational& second);

	// Boolean operators
		
		// Checks if the Rationals equal each other
		// Takes two Rationals (first and second)
		// Returns true if the Rationals equal, false otherwise
		friend bool operator == (const Rational& first, const Rational& second);

		// Checks if the Rationals aren't equal
		// Takes two Rationals (first and second)
		// Returns true if the Rationals aren't equal, false otherwise
		friend bool operator != (const Rational& first, const Rational& second);

		// Checks if the first Rational is less than the second Rational
		// Takes two Rationals (first and second)
		// Returns true if first is less than second, false otherwise
		friend bool operator < (const Rational& first, const Rational& second);

		// Checks if the first Rational is less than or equal to the second Rational
		// Takes two Rationals (first and second)
		// Returns true if first is less than or equal to second, false otherwise
		friend bool operator <= (const Rational& first, const Rational& second);

		// Checks if the first Rational is greater than the second Rational
		// Takes two Rationals (first and second)
		// Returns true if first is greater than second, false otherwise
		friend bool operator > (const Rational& first, const Rational& second);
		// Checks if the first Rational is greater than or equal to the second Rational
		// Takes two Rationals (first and second)
		// Returns true if first is greater than or equal to second, false otherwise
		friend bool operator >= (const Rational& first, const Rational& second);

	// I/O Operators
		
		// Inputs data values into the numerator and denominator of the Rational
		// Calls the istream by reference to extract the desired data values
		// Calls Rational by reference to receive the desired data values
		friend std::istream& operator >> (std::istream& in, Rational& first);

		// Outputs the Rational
		// Calls the ostream by reference to insert the desired values
		// Calls Rational by reference to output the desired values
		friend std::ostream& operator << (std::ostream& out, const Rational& first);

	private:
		
		// parameters to be used by functions
		int numerator;
		int denominator;
};	
