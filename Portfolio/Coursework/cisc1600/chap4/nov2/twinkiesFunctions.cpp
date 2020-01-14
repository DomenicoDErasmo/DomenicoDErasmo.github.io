// Domenico D'Erasmo
// 2 November 2017
// HW #7
// twinkiesFunctions.cpp
// Functions for twinkie.cpp
//  Using .cpp file instead of .h file to practice prototyping functions.

#include <iostream>

double coinValue(std::string coin) {	// determines the value of each coin and checks for invalid formats
	
	// variables
	double value;

	// processing
	if (coin == "dollar" || coin == "Dollar") {
		value = 1.00;
	} else if (coin == "quarter" || coin == "Quarter") {
		value = 0.25;
	} else if (coin == "dime" || coin == "Dime") {
		value = 0.10;
	} else if (coin == "nickel" || coin == "Nickel") {
		value = 0.05;
	} else if (coin == "penny" || coin == "Penny") {
		value = 0.01;
	} else {
		value = 0;
	}

	// output
	return value;
}
