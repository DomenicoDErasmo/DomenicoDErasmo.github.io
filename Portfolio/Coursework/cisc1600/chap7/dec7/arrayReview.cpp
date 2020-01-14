// Domenico D'Erasmo
// 7 December 2017
// Array Review
// Code that shows some understanding of arrays

#include <iostream>

// prototyping
void inputArraySize(int& arraySize);
void userInput(int inputArray[], int arraySize);
void arrayStatistics(int inputArray[], int arraySize);
void arraySearch(int inputArray[], int arraySize);
void arrayReplace(int inputArray[], int arraySize);
void arrayModify(int inputArray[], int arraySize);
void arrayClear(int inputArray[], int arraySize);
void userInterface(int inputArray[], int arraySize, bool& redoCheck);

int main() {

	// variables
	bool redoCheck = true;
	int arraySize, inputArray[arraySize] = {0};

	// prompts user for array size
	inputArraySize(arraySize);

	// prompts user for input of array
	userInput(inputArray, arraySize);

	// user interface
	do {
		userInterface(inputArray, arraySize, redoCheck);
	} while (redoCheck);

	return 0;
}
