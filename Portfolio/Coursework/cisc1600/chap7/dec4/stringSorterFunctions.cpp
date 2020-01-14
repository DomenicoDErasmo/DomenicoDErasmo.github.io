// Domenico D'Erasmo
// 4 December 2017
// HW #9
// Code to sort a string by its character frequencies
// stringSorter.cpp

#include <iostream>
#include <string>
#include <algorithm>

// prototyping
void initializeArray (char letterPlace[]);
std::string userInput ();
bool inputCleanse (char& stringCharacter);
int letterFrequencies (std::string inputString, int letterCount[]);
void sortFrequencies (int letterCount[], char letterPlace[]);
void programOutput (int letterCount[], char letterPlace[]);

int main () {
	
	// variables
	std::string inputString = "";
	int letterCount[26] = {0};
	char letterPlace[26];
	
	// initialize character array
	initializeArray(letterPlace);

	// input and input cleanse
	inputString = userInput ();
	
	// record letter frequencies
	letterFrequencies (inputString, letterCount);

	// sort frequencies in descending order
	sortFrequencies (letterCount, letterPlace);
	
	// output
	programOutput (letterCount, letterPlace);

	return 0;
}
