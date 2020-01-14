// Domenico D'Erasmo
// 30 November 2017
// Classwork
// Code that uses multiple arrays to book airplane seats.

#include <iostream>

// prototyping
void initializeArray (char seatArray[][6], int rowSize, int columnSize);
void display (char seatArray[][6], int rowSize, int columnSize);
void userInput(char seatArray[][6]);
bool redoCheck();

int main() {

	// variables
	int rowSize = 20, columnSize = 6;
	char seatArray[20][6];

	//initialize
	initializeArray (seatArray, rowSize, columnSize);
	
	do {
		// print display
		display (seatArray, rowSize, columnSize);

		// prompt user
		userInput (seatArray);
	} while (redoCheck());
	return 0;
}

void initializeArray (char seatArray[][6], int rowSize, int columnSize) {
	int rowCounter, columnCounter;
	for (columnCounter = 0; columnCounter < columnSize; columnCounter++) {
		for (rowCounter = 0; rowCounter < rowSize; rowCounter++) {
			seatArray[rowCounter][columnCounter] = 'a' + columnCounter;
		}
	}

}

void display (char seatArray[][6], int rowSize, int columnSize) {
	int rowCounter, columnCounter;

	for (rowCounter = 0; rowCounter < rowSize; rowCounter++) {
		std::cout << rowCounter + 1 << "\t";
		for (columnCounter = 0; columnCounter < columnSize; columnCounter++) {
			std::cout << seatArray[rowCounter][columnCounter] << " ";
		}
		std::cout << "\n";
	}
}

void userInput (char seatArray[][6]) {
	int rowNumber;
	char columnNumber;
	bool redoCheck = true;
	do {
		std::cout << "What seat do you want? (ROW COLUMN) : ";
		std::cin >> rowNumber >> columnNumber;
		if (((rowNumber >= 1) && (rowNumber <= 20)) && ((columnNumber >= 'a') && (columnNumber <= 'f'))) {
			seatArray[rowNumber - 1][columnNumber - 97] = 'x';
			redoCheck = false;
		} else {
			redoCheck = true;
		}
	} while (redoCheck == true);
}

bool redoCheck() {
	std::string redoPrompt;
	std::cout << "Want to book another seat? (Yes/No) : ";
	std::cin >> redoPrompt;
	if (redoPrompt == "Yes" || redoPrompt == "yes") {
		std::cout << std::string (50, '\n');
		return true;
	} else {
		return false;
	}
}
