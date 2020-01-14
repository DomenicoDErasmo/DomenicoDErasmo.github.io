// Domenico D'Erasmo
// 2 October 2017
// Code to use switch statement

#include <iostream>
using namespace std;

int main () {
	// variables
	char cityCode;

	// input
	cout << "Enter a city to fly to [C]hicago, [M]iami, or [P]ortland : ";
	cin >> cityCode;

	// processing
	switch (cityCode) {
		case 'C':
		case 'c':
			cout << "You're going to Chicago!" << endl;
			break;
		case 'M':
		case 'm':
			cout << "You're going to Miami!" << endl;
			break;
		case 'P':
		case 'p':
			cout << "You're going to Portland!" << endl;
			break;
		default:
			cout << "That is not a valid destination. Goodbye." << endl;
			break;
	}
	return 0;
}
