// Domenico D'Erasmo
// 12 October 2017
// Lab #6
// Keypad sourcecode
// Keypad.cpp

#include <iostream>
#include <string>
using namespace std;

int main() {
	// variables
	int index;
	char token;
	string input;
	
	// input
	cout << "Enter a string : " << endl;
	getline(cin,input);

	// translation
	for (index = 0; index < input.length(); index++){
		token = input.at(index);
		switch (token) {
			case 'A' :
			case 'a' :
			case 'B' :
			case 'b' :
			case 'C' :
			case 'c' :
				cout << "2";
				break;
			case 'D' :
			case 'd' :
			case 'E' :
			case 'e' :
			case 'F' :
			case 'f' :
				cout << "3";
				break;
			case 'G' :
			case 'g' :
			case 'H' :
			case 'h' :
			case 'I' :
			case 'i' :
				cout << "4";
				break;
			case 'J' :
			case 'j' :
			case 'K' :
			case 'k' :
			case 'L' :
			case 'l' :
				cout << "5";
				break;
			case 'M' :
			case 'm' :
			case 'N' :
			case 'n' :
			case 'O' :
			case 'o' :
				cout << "6";
				break;
			case 'P' :
			case 'p' :
			case 'Q' :
			case 'q' :
			case 'R' :
			case 'r' :
			case 'S' :
			case 's' :
			case 'T' :
			case 't' :
				cout << "7";
				break;
			case 'U' :
			case 'u' :
			case 'V' :
			case 'v' :
				cout << "8";
				break;
			case 'W' :
			case 'w' :
			case 'X' :
			case 'x' :
			case 'Y' :
			case 'y' :
			case 'Z' :
			case 'z' :
				cout << "9";
				break;
			default :
				cout << token;
				break;
		}
	}
	cout << endl;
	return 0;
}
