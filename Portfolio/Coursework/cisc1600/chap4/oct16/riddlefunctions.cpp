// Domenico D'Erasmo
// 16 October 2017
// HW #6
// Riddle source code using functions
// riddlefunctions.cpp
// Code for riddle using multiple functions
// Riddle:
	// Odd number
	// Digits add up to 27
	// Thousands place is 3x tens place
	// All digits are different

#include <iostream>

// stopped using "using namespace std" to try and shake the habit (different namespaces may conflict)

bool sumIs27(int sumCheck) {					// Checks if the sum of the numbers is 27
	int thousands, hundreds, tens, ones;
	thousands = (sumCheck / 1000);
	hundreds = (sumCheck / 100) % 10;
	tens = (sumCheck / 10) % 10;
	ones = sumCheck % 10;
	if ((thousands + hundreds + tens + ones) == 27) {
		return true;
	} else {
		return false;
	}
}

bool thousandsTens(int thousandsTensCheck) {			// Checks if the thousands place is triple the tens place
	int thousands, hundreds, tens, ones;
	thousands = (thousandsTensCheck / 1000);
	tens = (thousandsTensCheck / 10) % 10;
	if (thousands == tens*3) {
		return true;
	} else {
		return false;
	}
}


bool numberIsOdd(int oddCheck) {				// Checks if the number is odd
	if ((oddCheck%2)==1) {
		return true;
	} else {
		return false;
	}
}

bool digitsDifferent(int digitsDifferentCheck) {		// Checks if all of the digits are different
	int thousands, hundreds, tens, ones;
	thousands = (digitsDifferentCheck / 1000);
	hundreds = (digitsDifferentCheck / 100) % 10;
	tens = (digitsDifferentCheck / 10) % 10;
	ones = digitsDifferentCheck % 10;
	if ((thousands != hundreds) && (thousands != tens) && (thousands != ones) && (hundreds != tens) && (hundreds != ones) && (tens != ones)) {
		return true;
	} else {
		return false;
	}
}

int main() {
	// variables
	int number;
	
	// processing
	for (number=1000; number <= 9999; number++) {
		if (sumIs27(number) && thousandsTens(number) && numberIsOdd(number) && digitsDifferent(number)) {
			std::cout << number << " fits all of the criteria.\n";
		}
	}
	return 0;
}
