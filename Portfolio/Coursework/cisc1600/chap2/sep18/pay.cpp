// Domenico D'Erasmo
// 18 September 2017
// if-then-else condition to calculate pay

#include <iostream>
using namespace std;

int main() {
	// variables
	int hours;
	double grosspay, rate;

	// input
	cout << "How many hours did you work? ";
	cin >> hours;
	cout << "What is your hourly rate? ";
	cin >> rate;

	// conditions
	if (hours <= 40){
		grosspay = hours*rate;
		cout << "You earned " << grosspay << "dollars!" << endl;
	} else if (hours >40) {
		grosspay = (rate*40) + (1.5*(hours-40));
		cout << "You earned " << grosspay << "dollars!" << endl;
	}	
	return 0;
}
