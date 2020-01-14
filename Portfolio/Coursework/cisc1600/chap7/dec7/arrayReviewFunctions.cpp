// Domenico D'Erasmo
// 7 December 2017
// Array Review Functions

#include <iostream>

// prompts user for array size
void inputArraySize(int& arraySize) {
	bool redoCheck = false;
	do {
		std::cout << "Enter an array size : ";
		std::cin >> arraySize;
		if ((arraySize <= 0) || (std::cin.fail())) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Error: Invalid array size. Please try again.\n";
			redoCheck = true;
		}
	} while (redoCheck);
}

// prompts user to input values for array
void userInput(int inputArray[], int arraySize) {
	int loopIndex;
	bool redoCheck = true;
	for (loopIndex = 0; loopIndex < arraySize; loopIndex++) {
		do {
			std::cout << "Enter value #" << loopIndex + 1 << " : ";
			std::cin >> inputArray[loopIndex];
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(100, '\n');
			} else {
				redoCheck = false;
			}
		} while (redoCheck);
	}
}

// calculates min, max, sum, and average of array
void arrayStatistics(int inputArray[], int arraySize) {
	double sum = 0, average;
	int minCheck = inputArray[0], maxCheck = inputArray[0], sumLoopIndex, minMaxLoopIndex;
	for (sumLoopIndex = 0; sumLoopIndex < arraySize; sumLoopIndex++) {
		sum += inputArray[sumLoopIndex];
	}
	average = sum / arraySize;
	for (minMaxLoopIndex = 0; minMaxLoopIndex < arraySize; minMaxLoopIndex++) {
		if (minCheck > inputArray[minMaxLoopIndex]) {
			minCheck = inputArray[minMaxLoopIndex];
		}
		if (maxCheck < inputArray[minMaxLoopIndex]) {
			maxCheck = inputArray[minMaxLoopIndex];
		}
	}
	std::cout << "Maximum : " << maxCheck << "\n";
	std::cout << "Minimum : " << minCheck << "\n";
	std::cout << "Sum : " << sum << "\n";
	std::cout << "Average : " << average << "\n";
}

// searches array for postition of element
void arraySearch(int inputArray[], int arraySize) {
	int loopIndex, arrayQuery;
	bool queryFlag = false;
	std::cout << "Enter a value to find : ";
	std::cin >> arrayQuery;
	for (loopIndex = 0; loopIndex < arraySize; loopIndex++) {
		if (arrayQuery == inputArray[loopIndex]) {
			std::cout << arrayQuery << " was found at position " << loopIndex + 1 << ".\n";
			queryFlag = true;
		} 
	}
	if (queryFlag == false) {
		std::cout << "-1\n";
	}
}

// replaces all instances of a number in the array with a new number
void arrayReplace(int inputArray[], int arraySize) {
	int loopIndex, arrayQuery, arrayReplace, replaceCounter = 0;
	std::cout << "Enter a value to be replaced : ";
	std::cin >> arrayQuery;
	std::cout << "Enter a value to replace with : ";
	std::cin >> arrayReplace;
	for (loopIndex = 0; loopIndex < arraySize; loopIndex++) {
		if (arrayQuery == inputArray[loopIndex]) {
			inputArray[loopIndex] = arrayReplace;
			replaceCounter++;
		}
	}
	std::cout << "The value " << arrayQuery << " was replaced " << replaceCounter << " times.\n";
}

// modifies a specific index in the array
void arrayModify(int inputArray[], int arraySize) {
	int indexQuery, editValue;
	bool redoCheck = true;
	do {	
		std::cout << "Enter an array position to edit (1 to " << arraySize << ") : ";
		std::cin >> indexQuery;
		if ((indexQuery > 0) && (indexQuery <= arraySize)){
			redoCheck = false;
			std::cout << "Enter a new value : ";
			std::cin >> editValue;
			inputArray[(indexQuery - 1)] = editValue;
		} else {
			std::cout << "Error: Invalid index number.\n";
		}
	} while (redoCheck);
}

// clears one or all values of the array
void arrayClear(int inputArray[], int arraySize) {
	int clearCheck, loopIndex;
	std::cout << "Enter -1 to clear all values. Enter a specific index to clear that value.";
	std::cin >> clearCheck;
	if (clearCheck == -1) {
		for (loopIndex = 0; loopIndex < arraySize; loopIndex++) {
			inputArray[loopIndex] = 0;
			std::cout << "All of the values were cleared.\n";
		}
	} else if ((clearCheck >= 0) && (clearCheck < arraySize)) {
		inputArray[clearCheck] = 0;
		std::cout << "Index #" << clearCheck + 1 << " was cleared.\n";
	} else {
		std::cout << "No values were cleared.\n";
	}
}

// user interface
void userInterface(int inputArray[], int arraySize, bool& redoCheck) {
	bool redoInputCheck;
	double sum = 0, average;
	int loopIndex, minimum, maximum;
	std::string inputCommand;
	std::cout << "Position\tValue\n";
	for (loopIndex = 0; loopIndex < arraySize; loopIndex++) {
		std::cout << loopIndex + 1 << "\t\t" << inputArray[loopIndex] << "\n";
	}
	std::cout << "Clear - Clear Values\n";
	std::cout << "Find - Find Values\n";
	std::cout << "Modify - Modify Values\n";
	std::cout << "Quit - Quit Program\n";
	std::cout << "Replace - Replace Values\n";
	std::cout << "Statistics - Statistics of Values\n";
	std::cin >> inputCommand;
	if ((inputCommand == "Clear") || (inputCommand == "clear")) {
		arrayClear(inputArray, arraySize);
	} else if ((inputCommand == "Find") || (inputCommand == "find")) {
		arraySearch(inputArray, arraySize);
	} else if ((inputCommand == "Modify") || (inputCommand == "modify")) {
		arrayModify(inputArray, arraySize);
	} else if ((inputCommand == "Quit") || (inputCommand == "quit")) {
		redoCheck = false;
	} else if ((inputCommand == "Replace") || (inputCommand == "replace")) {
		arrayReplace(inputArray, arraySize);
	} else if ((inputCommand == "Statistics") || (inputCommand == "statistics")) {
		arrayStatistics(inputArray, arraySize);
	} else {
		std::cout << "Error : Invalid command entered. Please try again.\n";
	}
}
