// Domenico D'Erasmo
// 6 November 2017
// Extra Credit 1
// Code to find x number prime numbers.

#include <iostream>

void primeCheck(int numberOfPrimes);

int main() {
	
	// variables
	int numberOfPrimes;
	std::string redoProgramCheck;

	// input
	
	do {
		std::cout << "Welcome to Finding Primes!\n";
		std::cout << "How many prime numbers do you want to see : ";
		std::cin >> numberOfPrimes;
		if (numberOfPrimes < 1) {
			std::cout << "I can't search for " << numberOfPrimes << " prime numbers.\n";
			std::cout << "Would you like to try again? (Yes/No)\n";
			std::cin >> redoProgramCheck;
		} else if (numberOfPrimes == 1) {
			std::cout << "2\n";
			std::cout << "Would you like to try again? (Yes/No)\n";
			std::cin >> redoProgramCheck;
		} else {
			std::cout << "2 ";
			primeCheck(numberOfPrimes);
			std::cout << "\n";
			std::cout << "Would you like to try again? (Yes/No)\n";
			std::cin >> redoProgramCheck;
		}
	} while (redoProgramCheck == "Yes" || redoProgramCheck == "yes");	
	std::cout << "Have a nice day!\n";
}
