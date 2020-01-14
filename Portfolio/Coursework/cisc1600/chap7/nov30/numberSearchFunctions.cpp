// Domenico D'Erasmo
// 30 November 2017
// Lab #9
// Functions for code to enter and find numbers in an array
// numberSearchFunctions.cpp

#include <iostream>

int userInput(int& inputTracker) {
	int inputNumber;
	bool redoCheck = true;
	do {
		std::cout << "Input number " << inputTracker << " : ";
		std::cin >> inputNumber;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		} else {
			inputTracker++;
			redoCheck = false;
			return inputNumber;
		}
	} while (inputNumber);
}

bool findAndReplace (int queryNumber, int size, int arrayNumber[]) {
	int index;
	bool queryChecker;
	for (index = 0; index < size; index++) {
		if (queryNumber == arrayNumber[index]) {
			std::cout << queryNumber << " was at location " << index + 1 << ".\n";
			arrayNumber[index] = 0;
			queryChecker = true;
		}
	} 
	if (queryChecker == false) {
		std::cout << queryNumber << " was not in the list!\n";
		std::cout << "Goodbye!\n";
		return false;
	} else {
		return true;
	}
}
