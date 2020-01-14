// Domenico D'Erasmo
// 2 November 2017
// Lab #7
// Password Check Function Library
// checks.h
// I use four different functions to check for valid password conditions. Using only one would probably be quicker, but I am using this to practice writing new functions.

#include <iostream>
#include <string>

bool lengthCheck(std::string password) {	// checks for the length of the password
	if (password.length() >= 10) {
		return true;
	} else {
		return false;
	}
}

bool upperCaseCheck(std::string password) {	// Checks for the presnce of an uppercase letter. This is functionally the same as the next two functions.
	int stringLength = password.length(), stringIndex, caseCheck = 0;
	for (stringIndex = 0; stringIndex < stringLength; stringIndex++) {
		switch(password.at(stringIndex)) {
			case 'A' :
			case 'B' :
			case 'C' :
			case 'D' :
			case 'E' :
			case 'F' :
			case 'G' :
			case 'H' :
			case 'I' :
			case 'J' :
			case 'K' :
			case 'L' :
			case 'M' :
			case 'N' :
			case 'O' :
			case 'P' :
			case 'Q' :
			case 'R' :
			case 'S' :
			case 'T' :
			case 'U' :
			case 'V' :	
			case 'W' :
			case 'X' :
			case 'Y' :
			case 'Z' :
				caseCheck++;
				break;
			default :
				break;
		}
		if (caseCheck >= 1) {
			return true;
			break;
		}
	}
	if (caseCheck == 0) {
		return false;
	}
}

bool digitCheck(std::string password) {
	int stringLength = password.length(), stringIndex, caseCheck = 0;
	for (stringIndex = 0; stringIndex < stringLength; stringIndex++) {
		switch(password.at(stringIndex)) {
			case '0' :
			case '1' :
			case '2' :
			case '3' :
			case '4' :
			case '5' :
			case '6' :
			case '7' :
			case '8' :
			case '9' :
				caseCheck++;
				break;
			default :
				break;
		}
		if (caseCheck >=1) {
			return true;
			break;
		}
	}
	if (caseCheck == 0) {
		return false;
	}
}

bool specialCharacterCheck(std::string password) {
	int stringLength = password.length(), stringIndex, caseCheck = 0;
	for (stringIndex = 0; stringIndex < stringLength; stringIndex++) {
		switch(password.at(stringIndex)) {
			case '!' :
			case '@' :
			case '#' :
			case '$' :
			case '%' :
			case '^' :
			case '&' :
			case '*' :
			case '(' :
			case ')' :
				caseCheck++;
				break;
			default :
				break;
		}
		if (caseCheck >=1) {
			return true;
			break;
		}
	}
	if (caseCheck == 0) {
		return false;
	}
}
