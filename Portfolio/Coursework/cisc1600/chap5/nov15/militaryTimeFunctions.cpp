// Domenico D'Erasmo
// 15 November 2017
// HW #8
// Functions of the code to convert military time to regular time
// Objectives:
// 	Use at least three functions
// 		Input, Conversion, Output
// 	Call-by-reference parameter of type char for the time (AM vs PM)
// 	Loop to repeat the program upon request

#include <iostream>
#include <string>

// takes user input and determines AM or PM using call-by-reference
std::string userInput(char& timeHalf) {
	std::string timeInput, finalTimeInput;
	bool checkForValidInput = false;

	do {
		std::cout << "Enter a time to convert (HH:MM) : ";
		std::cin >>timeInput;
		if ((timeInput.length() == 5) && (((timeInput.at(0) >= '0') && (timeInput.at(0) < '2')) || ((timeInput.at(0) == '2') && ((timeInput.at(1) >= '0') && (timeInput.at(1) < '4'))) && (timeInput.at(2) == ':') && ((timeInput.at(3) >= '0') && (timeInput.at(3) < '5')) && ((timeInput.at(4) >= '0') && (timeInput.at(4) <= '9')))) {
			checkForValidInput = false;
			finalTimeInput = timeInput;
		} else {
			checkForValidInput = true;
			std::cout << "The time you entered was an invalid format. Please try again.\n";
		}
	} while (checkForValidInput);
	if ((finalTimeInput.at(0) == '0' || ((finalTimeInput.at(0) == '1') && (finalTimeInput.at(1) < '2')))) {
		timeHalf = 'a';
	} else {
		timeHalf = 'p';
	}
	return finalTimeInput;
}

// Converts time from 24 hours to 12 hours
std::string timeConversion(std::string timeToConvert) {
	if (timeToConvert.at(0) == '1') {
		if (timeToConvert.at(1) == '3') {
			timeToConvert.at(0) = '0';
			timeToConvert.at(1) = '1';
		} else if (timeToConvert.at(1) == '4') {
			timeToConvert.at(0) = '0';
			timeToConvert.at(1) = '2';
		} else if (timeToConvert.at(1) == '5') {
			timeToConvert.at(0) = '0';
			timeToConvert.at(1) = '3';
		} else if (timeToConvert.at(1) == '6') {
			timeToConvert.at(0) = '0';
			timeToConvert.at(1) = '4';
		} else if (timeToConvert.at(1) == '7') {
			timeToConvert.at(0) = '0';
			timeToConvert.at(1) = '5';
		} else if (timeToConvert.at(1) == '8') {
			timeToConvert.at(0) = '0';
			timeToConvert.at(1) = '6';
		} else if (timeToConvert.at(1) == '9') {
			timeToConvert.at(0) = '0';
			timeToConvert.at(1) = '7';
		}
	}
	if (timeToConvert.at(0) == '2') {
		if (timeToConvert.at(1) == '0') {
			timeToConvert.at(0) = '0';
			timeToConvert.at(1) = '8';
		} else if (timeToConvert.at(1) == '1') {
			timeToConvert.at(0) = '0';
			timeToConvert.at(1) = '9';
		} else if (timeToConvert.at(1) == '2') {
			timeToConvert.at(0) = '1';
			timeToConvert.at(1) = '0';
		} else if (timeToConvert.at(1) == '3') {
			timeToConvert.at(0) = '1';
			timeToConvert.at(1) = '1';
		} 
	}
	if (timeToConvert.at(0) == '0') {
		if (timeToConvert.at(1) == '0') {
			timeToConvert.at(0) == '1';
			timeToConvert.at(1) == '2';
		}
	}
	return timeToConvert;
}

// Check to redo program
bool redoProgram() {
	std::string redoCheck;

	std::cout << "Do you want to use the program again? Yes/No : ";
	std::cin >> redoCheck;
	if ((redoCheck == "Yes") || (redoCheck == "yes")) {
		return true;
	} else {
		return false;
	}
}
