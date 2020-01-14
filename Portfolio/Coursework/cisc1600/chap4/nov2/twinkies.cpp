// Domenico D'Erasmo
// 2 November 2017
// HW #7
// Twinkies Vending Machine Source Code
// twinkies.cpp
// The user will be prompted to put in coins until $3.50 or more has been added.

#include <iostream>

double coinValue(std::string coin);

int main() {

	// initalization of credit format (always displays $x.xx)
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);

	// variables
	double credit = 0, change;
	std::string coin;

	// input and call to function in twinkiesFunctions.cpp
	std:: cout << "The cost of a deep-fried twinkie is $3.50. You may enter coins one in a time by typing 'dollar,' 'quarter,' 'dime,' 'nickel,' or 'penny.'\n";
	do {
		std::cout << "Credit : $" << credit << ". Enter the next coin : ";
		std::cin >> coin;
		credit = credit + coinValue(coin);
		if (coinValue(coin) == 0) {
			std::cout << "Invalid data was entered. Please try again.\n";
		}
	} while (credit < 3.50);

	// basic processing for change and output
	change = credit - 3.50;
	std::cout << "Enjoy your twinkie! Your change is $" << change << ".\n";
	return 0;
}
