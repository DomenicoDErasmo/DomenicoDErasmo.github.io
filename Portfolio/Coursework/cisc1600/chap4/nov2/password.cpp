// Domenico D'Erasmo
// 2 November 2017
// Lab #7
// Password Source Code
// password.cpp
// Code checks to see if a password meets these criterion:
// 	10+ characters
// 	1+ uppercase letts
// 	1+ digits
// 	1+ special characters
// A header file with its own functions is included, to practice including custom header files in C++.

#include <iostream>
#include <string>
#include "checks.h"

int main() {

	// variable
	std::string password; 

	// input
	std::cout << "The password must contain : \n";
	std::cout << "Ten or more characters.\n";
	std::cout << "At least one uppercase letter.\n";
	std::cout << "At least one digit.\n";
	std::cout << "At least one special character !@#$%^&*().\n";
	std::cout << "Enter a password : ";

	// storage
	std::cin >> password;
	
	// processing using functions from custom header
	if ((lengthCheck(password)) && (upperCaseCheck(password)) && (digitCheck(password)) && (specialCharacterCheck(password))) {
		std::cout << "The password is valid!\n";
	} else {
		std::cout << "The password is invalid!\n";
	}
	return 0;
}
