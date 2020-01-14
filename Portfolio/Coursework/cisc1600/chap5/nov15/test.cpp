// Domenico D'Erasmo
// 16 November 2017
// Test of some code for HW #8

#include <iostream>

int main(){
	std::string timeInput;
	bool checkForValidInput = false;

	do {
		std::cout << "Enter a time to convert : (HH:MM)";
		std::cin >>timeInput;
		if ((timeInput.length() == 5) && (((timeInput.at(0) >= '0') && (timeInput.at(0) < '2')) || ((timeInput.at(0) == '2') && ((timeInput.at(1) >= '0') && (timeInput.at(1) < '5'))) && (timeInput.at(2) == ':') && ((timeInput.at(3) >= '0') && (timeInput.at(3) < '5')) && ((timeInput.at(4) >= '0') && (timeInput.at(4) <= '9')))) {
			checkForValidInput = false;
			std::cout << timeInput << std::endl;
		} else {
			checkForValidInput = true;
			std::cout << "The time you entered was an invalid format. Please try again.\n";
		}
	} while (checkForValidInput);
}

