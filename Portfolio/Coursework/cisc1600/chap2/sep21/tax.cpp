// Domenico D'Erasmo
// 21 September 2017
// Code to determine taxes

#include <iostream>
using namespace std;

int main(){
	// initializes formatting
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	// variables
	int hours;
	double rate, pretax;

	// output
	cout << "Hello there. Welcome to the tax program." << endl;
	cout << "How many hours did you work? " << endl;
	cin >> hours;	
	cout << "What is your hourly rate? " << endl;
	cin >> rate;
	pretax = rate*hours;
	cout << "It looks like your pay before taxes is $" << pretax << "." << endl;
	return 0;
}
