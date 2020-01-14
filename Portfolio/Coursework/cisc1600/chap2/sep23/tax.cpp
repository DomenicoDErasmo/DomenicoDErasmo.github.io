// Domenico D'Erasmo
// 23 September 2017
// Code to determine

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// initalizes decimal format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// variables
	int hours, dependents, loop = 1;
	double pay, wage = 16.78, ss, fed = 0.14, state = 0.05, unionfee = 10, insurance;
	
	//prompts
	do {
		loop = 0;
		cout << "Enter number of hours worked : ";
		cin >> hours;
		if (hours > 40) {
			pay = 40*wage + wage*(hours-40);
		} else pay = hours*wage;
		cout << "Enter the number of dependents : ";
		cin >> dependents;
		if (dependents < 3) {
			ss = 0.06;
			insurance = 0;
		} else if (dependents >= 3) {
			ss = 0.08;
			insurance = 35;
		}
		cout << setw(20) << right << "Gross pay is" << setw(10) << right << pay << endl << endl;
		cout << setw(20) << right << "SS tax is" << setw(10) << right << 0-(pay*ss) << endl;
		cout << setw(20) << right << "Fed tax is" << setw(10) << right << 0-(pay*fed) << endl;
		cout << setw(20) << right << "State tax is" << setw(10) << right << 0-(pay*state) << endl;
		cout << setw(20) << right << "Union dues is" << setw(10) << right << 0-(unionfee) << endl;
		cout << setw(20) << right << "Insurance is" << setw(10) << right << 0-(insurance) << endl << endl;
		cout << setw(20) << right << "Take home pay is" << setw(10) << right <<pay*(1-ss-fed-state)-unionfee-insurance << endl;
		cout << "Do you want to run the program again? Press 1 to reuse the program. : ";
		cin >> loop;
	} while (loop == 1);
	return 0;
}
