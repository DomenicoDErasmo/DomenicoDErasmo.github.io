// Domenico D'Erasmo
// 25 September 2017
// Code that uses do-while-loop

#include <iostream>
using namespace std;
int main() {
	// Variables
	int length, width, area;
	char rerun;
	
	do {
		// Prompts
		cout << "Area equals length times width." << endl << "Please enter a length in feet : ";
		cin >> length;
		cout << "Now please enter a width in feet : ";
		cin >> width;

		// Processing
		area = length*width;
		cout << "The area of a carpet " << length << " feet long and " << width << " feet wide is " << area << " square feet." << endl;
		cout << "Would you like to run another calculation? Y=yes, N=No : "; 
		cin >> rerun;
	} while (rerun == 'y' || rerun == 'Y');
	cout << "Have a nice day!" << endl;
	return 0;
}
