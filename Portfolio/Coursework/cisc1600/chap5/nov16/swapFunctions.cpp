// Domenico D'Erasmo
// 16 November 2017
// Functions for program that uses call-by-reference to swap two numbers

#include <iostream>

void getNumbers(int& firstInput, int& secondInput) {
	std::cout << "Enter two integers : ";
	std::cin >> firstInput  >> secondInput;
}

void swapValues(int& firstArgument, int& secondArgument) {
	firstArgument = firstArgument + secondArgument;
	secondArgument = firstArgument - secondArgument;
	firstArgument = firstArgument - secondArgument;
}

void showResults(int firstOutput, int secondOutput) {
	std::cout << "The two numbers are " << firstOutput << " and " << secondOutput << ".\n";
}
