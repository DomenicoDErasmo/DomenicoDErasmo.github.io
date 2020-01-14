// Domenico D'Erasmo
// 27 October 2017
// CISC 1600 Midterm
// Lab Midterm 2

#include <iostream>
// not including the std namespace to break the habit of relying on namespaces

int main() {
	
	// variables
	int length, lengthCounter, widthCounter, width;
	char shapeCharacter; 
	std::string promptTriangle;
	
	// input
	std::cout << "Please specify a side length : ";
	std::cin >> length;
	std::cout << "Please specify a character : ";
	std::cin >> shapeCharacter;

	// processing
	width = length;
	for (lengthCounter = 1; lengthCounter <= length; lengthCounter++) {
		for (widthCounter = 1; widthCounter <= width; widthCounter++) {
			std::cout << shapeCharacter;
		}
		std:: cout << "\n";
	}
	
	// Triangle extra credit
	std::cout << "Would you like a triangle with the same side length? (Yes/No) ";
	std::cin >> promptTriangle;
	if (promptTriangle == "Yes" || promptTriangle == "yes") {
		for (width = 1; width <= length; width++) {
			for (widthCounter = 1; widthCounter <= width; widthCounter++) {
				std::cout << shapeCharacter;
			}
		std::cout << "\n";
		}
	}
	std::cout << "Have a nice day!\n";
	return 0;
}
