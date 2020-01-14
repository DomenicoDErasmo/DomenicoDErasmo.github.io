// Domenico D'Erasmo
// 30 November 2017
// Lab #9
// Code to enter and find numbers in an array
// numberSearch.cpp

#include <iostream>

int userInput(int& inputTracker);
bool findAndReplace (int queryNumber, int size, int arrayNumber[]);
int main() {

	// variables
	int inputTracker = 1, size = 6, arrayNumber[size], initializeIndex = size, displayOutput, queryNumber;
	
	//initialize with input
	for (initializeIndex = 0; initializeIndex < size; initializeIndex++) {
		arrayNumber[initializeIndex] = userInput(inputTracker);
	}
	do {
		std::cout << "Current list: ";
		for (displayOutput = 0; displayOutput < size; displayOutput++) {
			std::cout << arrayNumber[displayOutput] << " ";
		}
		std::cout << "\n";
		std::cout << "Enter a query number: ";
		std::cin >> queryNumber;
	} while (findAndReplace(queryNumber, size, arrayNumber));
}
