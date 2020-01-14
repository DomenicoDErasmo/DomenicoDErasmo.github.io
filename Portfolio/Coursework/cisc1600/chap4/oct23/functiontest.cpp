// Domenico D'Erasmo
// 23 October 2017
// Test of weaving functions

#include <iostream>
#include "functiontest2.h"

// function to call upon
void printFunction(int number);

int main() {
	
	// variables
	int counter, counterMax;

	// input
	std::cout << "Enter a number : ";
	std::cin >> counterMax;
	for (counter = 0; counter <= counterMax; counter++) {
		printFunction(counter);
	}
	return 0;
}
