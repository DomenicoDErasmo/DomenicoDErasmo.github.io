// Domenico D'Erasmo
// 16 November 2017
// Program that uses call-by-reference to swap two numbers

#include <iostream>

// prototypes
void getNumbers(int& firstInput, int& secondInput);
void swapValues(int& firstArgument, int& secondArgument);
void showResults(int firstOutput, int secondOutput);

int main() {
	
	// variables
	int firstNumber = 0, secondNumber = 0;
	
	// processing
	getNumbers(firstNumber, secondNumber);
	swapValues(firstNumber, secondNumber);
	showResults(firstNumber, secondNumber);

	return 0;
}
