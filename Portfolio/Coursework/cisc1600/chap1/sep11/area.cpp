// Domenico D'Erasmo
// 11 September 2017
// Program to calculate area from integers.

#include <iostream>
using namespace std;

int main()
{
	// Variables
	int length, width;
	char redo;
	
	//Processing and Input
	do {
		cout << "Welcome to the area finder!" << endl;
		cout << "Enter a desired length." << endl;
		cin >> length;
		cout << "Enter a desired width." << endl;
		cin >> width;
		int area = length*width;
		cout << "The area is " << area << "." << endl;
		cout << "Do you want to use the area finder again?" << endl;
		cin >> redo;
	} while (redo == 'y' || redo == 'Y');
	return 0;
}
