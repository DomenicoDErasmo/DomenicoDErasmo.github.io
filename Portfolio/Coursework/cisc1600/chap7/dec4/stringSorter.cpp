// Domenico D'Erasmo
// 4 December 2017
// HW #9
// Functions for code to sort a string by its character frequencies
// stringSorterFunctions.cpp

#include <iostream>
#include <string>
#include <algorithm>

// initializes letterPlace
void initializeArray (char letterPlace[]) {
	int loopIndex;
	for (loopIndex = 0; loopIndex < 26; loopIndex++) {
		letterPlace[loopIndex] = 'a' + loopIndex;
	}
}

// removes any nonalphabetic characters
bool inputCleanse (char& stringCharacter) {
	if (((stringCharacter >= 'a') && (stringCharacter <= 'z')) || ((stringCharacter >= 'A') && (stringCharacter <= 'Z'))) {
		return false;
	} else {
		return true;
	}
}

// prompts the user for a string, and then cleans input in inputCleanse
std::string userInput () {
	std::string inputString;
	std::cout << "Enter a string to parse for frequency : ";
	std::getline(std::cin, inputString);
	inputString.erase(std::remove_if(inputString.begin(), inputString.end(), &inputCleanse), inputString.end());
	return inputString;
}

// determines letter frequencies
int letterFrequencies (std::string inputString, int letterCount[]) {
	char letterOfString;
	int loopIndex;
	for (loopIndex = 0; loopIndex < inputString.length(); loopIndex++) {
		for (letterOfString = 'a'; letterOfString < 'z'; letterOfString++) {
			if ((inputString.at(loopIndex) == letterOfString) || (inputString.at(loopIndex) == letterOfString - 32)) {
				letterCount[letterOfString - 'a']++;
			}
		}
	}
}

// sorts frequencies in ascending order
void sortFrequencies (int letterCount[], char letterPlace[]) {
	int arrayIndex, compareIndex, frequencyTemp;
	char letterTemp;

	for (arrayIndex = 0; arrayIndex < 26; arrayIndex++) {
		for (compareIndex = 0; compareIndex < 26; compareIndex++) {
			if (letterCount[arrayIndex] < letterCount[compareIndex]) {
				
				// swaps both letterCount and letterPlace
				frequencyTemp = letterCount[arrayIndex];
				letterCount[arrayIndex] = letterCount[compareIndex];
				letterCount[compareIndex] = frequencyTemp;
				letterTemp = letterPlace[arrayIndex];
				letterPlace[arrayIndex] = letterPlace[compareIndex];
				letterPlace[compareIndex] = letterTemp;
			}
		}
	}
}

// prints nonzero letters and their frequencies from greatest to least
void programOutput (int letterCount[], char letterPlace[]) {
	int loopIndex;
	for (loopIndex = 25; loopIndex >= 0; loopIndex--) {
		if (letterCount[loopIndex] != 0) {
			std::cout << letterPlace[loopIndex] << " - " << letterCount[loopIndex] << "\n";
		} else {
			continue;
		}
	}
}
