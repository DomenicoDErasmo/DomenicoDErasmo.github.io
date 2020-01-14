// Domenico D'Erasmo
// 15 November 2017
// HW #8
// Code to convert military time to regular time
// Objectives:
// 	Use at least three functions
// 		Input, Conversion, Output
// 	Call-by-reference parameter of type char for the time (AM vs PM)
// 	Loop to repeat the program upon request

#include <iostream>

// prototyped functions
std::string userInput(char& timeHalf);
std::string timeConversion(std::string timeToConvert);
bool redoProgram();

int main() {
	
	// variables
	std::string timeToChange, newTime;
	char timeHalf;
	
	do {
		// input
		timeToChange = userInput(timeHalf);

		// processing
		newTime = timeConversion(timeToChange);

		// output
		std::cout << "The time is " << newTime << timeHalf << ".\n";
	} while (redoProgram()); 	
	return 0;
}
