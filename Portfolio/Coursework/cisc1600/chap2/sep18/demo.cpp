// Domenico D'Erasmo
// 18 September 2017
// Code will demo if-then to show even/odd numbers.

#include <iostream>
using namespace std;

int main() {
	// variable
	int number;

	// input
	cout << "Enter a number to check." << endl;
	
	//storage
	cin >> number;

	//check and print result
	if (number%2 == 0) {
		cout << number << " is an even number." << endl;
	} else cout << number << " is an odd number." << endl;
	return 0;
}
