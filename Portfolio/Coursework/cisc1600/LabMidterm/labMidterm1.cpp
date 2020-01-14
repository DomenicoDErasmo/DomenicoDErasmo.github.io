// Domenico D'Erasmo
// 27 October 2017
// CISC 1600 Midterm
// Lab Midterm 1

#include <iostream>

// not using the std namespace to break free of the habit

int main() {
	
	// variables
	int number1, number2, factorCheck, GCF, inputCheck = 0;
	std::string reuseProgram;
	
	do {
		//  input
		std::cout << "Enter the two numbers : ";
		std::cin >> number1 >> number2;

		// processing
		for (factorCheck = 1; (factorCheck < number1) || (factorCheck < number2); factorCheck++) {
			if ((number1 % factorCheck == 0) && (number2 % factorCheck == 0)) {
				GCF = factorCheck;
			}
		}
		
		// output
		std::cout << " The greatest common factor of " << number1 << " and " << number2 << " is " << GCF << ".\n";
		
		// redo
		std::cout << "Would you like to use the program again? (Yes/No) ";
		std::cin >> reuseProgram;

	} while (reuseProgram == "yes" || reuseProgram == "Yes");
	std::cout << "Have a nice day!\n";
	return 0;
}
