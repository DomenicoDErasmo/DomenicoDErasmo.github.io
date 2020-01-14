// Domenico D'Erasmo
// 20 December 2017
// Validate Phone Number

#include <iostream>
#include <string>

// prototyping
bool functionVerify(std::string phoneNumber);

int main() {
	
	// variables
	std::string phoneNumber, redoInput;
	bool redoCheck;
	
	do {
		// output
		std::cout << "Enter a telephone string ie. 123-456-7890 : ";
		std::cin >> phoneNumber;

		// processing and output
		if (functionVerify(phoneNumber)) {
			std::cout << "This is in a valid telephone number format!\n";
		} else {
			std::cout << "This is NOT in a valid telephone number format!\n";
		}

		// prompt for redo
		std::cout << "Would you like to check another telephone number (yes/no)? ";
		std::cin >> redoInput;
		if ((redoInput == "Yes") || (redoInput == "yes")) {
			redoCheck = true;
		} else {
			redoCheck = false;
			std::cout << "Have a nice day!\n";
		}
	} while (redoCheck);
	return 0;
}

// verify validity of string
bool functionVerify(std::string phoneNumber) {

	// variables
	int checkIndex, flag = 0;

	// processing
	if (phoneNumber.length() == 12) {
		for (checkIndex = 0; checkIndex < 12; checkIndex++) {
			if ((checkIndex != 3) && (checkIndex !=7)) {
				if (!((phoneNumber.at(checkIndex) >= '0') && (phoneNumber.at(checkIndex) <= '9'))) {
					flag++;
				}
			} else {
				if (phoneNumber.at(checkIndex) != '-') {
					flag++;
				}
			}
		}
	} else {
		flag++;
	}

	// return conditionals
	if (flag == 0) {
		return true;
	} else {
		return false;
	}
}
