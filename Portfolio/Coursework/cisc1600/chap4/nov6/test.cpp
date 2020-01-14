// Domenico D'Erasmo
// 6 November 2017
// Testing square root to int conversion for extra credit assignment.

#include <iostream>
#include <math.h>

int main() {
	
	// variables
	int testOutput, testNumber;

	// input
	std::cout << "Enter a number to check : ";
	std::cin >> testNumber;

	// processing
	testOutput = sqrt(testNumber);
	
	// output
	std::cout << "The output number is " << testOutput << ".\n";
	return 0;
}
