// Domenico D'Erasmo
// 5 October 2017
// Lab #5
// Four-function calculator

#include <iostream>
using namespace std;

int main() {
	//variables
	int inputA, inputB, loopCheck;
	double result;
	char operation;
	do {
		cout << "Enter an equation or 0x0 to exit: ";
		cin >> inputA >> operation >> inputB;
		
		// cin.fail is used to check for faulty data, which would cause an infinite error loop
		if (cin.fail()){ 
			cout << "You entered invalid data. Please try again." << endl;

			// clear and ignore are used to get rid of the error to prevent a loop
			cin.clear();
			
			// ignores up to 10 characters (buffer) and ignores up until the end of the line (defualt is end of file)
			cin.ignore(10, '\n');
		} else {
			switch (operation) {
				case '+':
					result = inputA + inputB;
					cout << inputA << " " << operation << " " << inputB << " is " << result << " ." << endl;
					break;
				case '-':
					result = inputA - inputB;
					cout << inputA << " " << operation << " " << inputB << " is " << result << " ." << endl;
					break;
				case 'x':
				case '*':
					if (inputA == 0 && inputB == 0){
						cout << "Thanks for using the calculator. Goodbye." << endl;
						loopCheck++;
					} else {
						result = inputA * inputB;
						cout << inputA << " " << operation << " " << inputB << " is " << result << " ." << endl;
					} break;
				case '/':
					if (operation == '/' && inputB == 0){
						cout << "Error -- cannot divide by 0." << endl;
					} else {
						result = inputA / inputB;
						cout << inputA << " " << operation << " " << inputB << " is " << result << " ." << endl;
					} break;
				defualt:
					cout << "You did not enter a valid operation. Please try again." << endl;
			}
		}
	} while (loopCheck == 0);
	return 0;
}	
