// Domenico D'Erasmo
// Lab #7
// 3 April 2018

#include <iostream>

// Rational number class
// Rational numbers can be expressed as numerator/denominator
// This class has three data types, all of which are private members of the class :
//      1. numerator: the numerator of the rational number
//      2. denominator: the denominator of the rational number
//      3. name: the name of the rational number
//              Note: name was not originally part of the lab. I added it in to make the output more
//              presentable, so that the user would know which rational number is being referred to.
// This class has one constructor, which is a public member of the class:
//      Rational (int numerator = 0, int denominator = 1)
// This class has several functions, all of which are public memebrs of the class :
//      1. userInput - prompts user for input for the rational number's data values
//      2. output - provides user with output, identifying the output rational number and expressing it in numerator/denominator form
//      3. getNumerator - gets numerator so it can be accessed publicly
//      4. getDenominator - gets denominator so it can be accessed publicly
//      5. getName - gets name so it can be accessed publicly
//      6. sum - makes a rational number equal to two other fractions
//      7. isEqual - checks if the two given rational numbers are equal by comparing them to an error margin of 0.01%

class Rational
{
	public:
	
		// creates a rational number with form numerator/denominator
		// numeratorInput is assigned to the numerator of the rational number or to 0 by default
		// denominatorInput is assigned to the denominator of the rational number or to 1 by default
		// nameInput is assigned to the name of the rational number
		Rational (int numeratorInput = 0, int denominatorInput = 1, std::string nameInput = "Blank");
		
		// uses input to create denominator
		void userInput();
		
		// creates output
		void output();
		
		// accesses numerator
		int getNumerator();
		
		// accesses denominator
		int getDenominator();

		// accesses rational number name
		std::string getName();
		
		// makes the rational number equal to the sum of the two rational numbers given as arguments, redundantly used accessor functions to verify that they work
		void sum (const Rational& first, const Rational& second);
		
		// checks if the two rational numbers are equal, through these three steps:
		//	1. cast the numerators and denominators as doubles
		//	2. divide numerators by denominators
		//	3. check if the values are within a relative threshhold of error
		bool isEqual (const Rational& first, const Rational& second);
		
		// modifies the numerator and denominator using three parameters:
		//	1. int numeratorInput - sets numerator to this value
		//	2. int denominatorInput - sets denominator to this value
		void set (int numeratorInput, int denominatorInput);		
		// makes the rational number equal to the product of the two rational numbers given as arguments
		void product (const Rational& first, const Rational& second);
		
		// simplifies the rational number using greatest common factor
		void simplify();
		
	private:
		
		// parameters to be used by functions
		int numerator;
		int denominator;
		std::string name;
};	
