// Domenico D'Erasmo
// 10 October 2017
// HW #5
// Cost of phone call

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// initalizes decimal format
	cout.setf(ios::fixed);
	cout.precision(2);
	// variables
	int dayCheck = 0, dayValue, timeHour, timeMinutes, timeHundreds, timeValue, minutes, minuteCheck = 0, timeCheck = 0;
	char dayOne, dayTwo, timeColon, programLoop;
	double costPerMinute, cost;
	
	// process
	do {
		// Input
		do{
			cout << "On what day of the week are you calling?" << endl;
			cout << "Your choices are [Mo]nday, [Tu]esday. [We]dnesday, [Th]ursday, [Fr]iday, [Sa]turday, and [Su]nday : ";
			cin >> dayOne >> dayTwo;
			
			// Checks for proper day format. dayValue starts from 0 = Monday to 6 = Sunday.
			switch (dayOne) {
				case 'M':	// Monday
				case 'm':
					switch (dayTwo) {
						case 'O' :
						case 'o' :
							dayValue = 0;
							dayCheck++;
							break;
						default :
							break;
					} break;
				case 'T' :	// Tuesday and Thursday
				case 't' :
					switch (dayTwo) {
						case 'U' :
						case 'u' :
							dayValue = 1;
							dayCheck++;
							break;
						case 'H' :
						case 'h' :
							dayValue = 3;
							dayCheck++;
							break;
						default :
							break;
					} break;
				case 'W' :	// Wednesday
				case 'w' :
					switch (dayTwo) {
						case 'E' :
						case 'e' :
							dayValue = 2;
							dayCheck++;
							break;
						default :
							break;
					}
				case 'F' :	// Friday
				case 'f' :
					switch (dayTwo) {
						case 'R' :
						case 'r' :
							dayValue = 4;
							dayCheck++;
							break;
						default :
							break;
					}
				case 'S' :	// Saturday and Sunday
				case 's' :
					switch (dayTwo) {
						case 'A' :
						case 'a' :
							dayValue = 5;
							break;
						case 'U' :
						case 'u' :
							dayValue = 6;
							dayCheck++;
							break;
						default :
							break;
					}
				default :
					break;
			}
			if (dayCheck == 0) cout << "That was not a valid date. Please try again." << endl;
		} while (dayCheck == 0);

		// Check for valid time. A time like 1180 or 2600 or even "bdfsnbsdfkngfsk" is not a valid time and must be dealt with accordingly.
		do {
			cout << "What time will you start your call? Use the format hours:minutes, like 13:30 : ";
			cin >> timeHour >> timeColon >> timeMinutes;
			if (cin.fail() || timeColon != ':' || timeMinutes >=60) {
				cout << "Invalid data was answered. Please try again." << endl;
				cin.clear();
				cin.ignore(100,'\n');
			} else if (timeHour >= 8 && timeHour <= 18) { // Sets the time type to determine weekday call rate. A time value of 0 is from 8:00am to 6:00pm, whereas a time value of 1 is from 6:00pm to 8:00 am
				timeValue = 0;
				timeCheck++;
			} else if ((timeHour >=0 && timeHour < 8) || (timeHour > 18 && timeHour < 24)) {
				timeValue = 1;
				timeCheck++;
			} else cout << "Invalid data was answered. Please try again." << endl;
		} while (timeCheck == 0);
		
		// Check for a valid number of minutes. Similar to above.
		do {
			cout << "How many minutes long will your call be? ";
			cin >> minutes;
			if (cin.fail()) {
				cout << "Invalid data was entered. Please try again." << endl;
				cin.clear();
				cin.ignore(100,'\n');
			} else minuteCheck++;
		} while (minuteCheck == 0);
		if ((dayValue >= 0 && dayValue < 5) || timeValue == 0) {
			costPerMinute = 0.40;
		} else if ((dayValue >= 0 && dayValue < 5) || timeValue == 1) {
			costPerMinute = 0.25;
		} else if ( dayValue == 5 || dayValue == 6) {
			costPerMinute = 0.15;
		}
		cost = costPerMinute * minutes;
		if (timeMinutes == 0) {
			switch (dayValue) {
				case 0 :
					cout << "A call on Monday starting at " << timeHour << ":00 and lasting for " << minutes << " minutes costs $" << cost << "." << endl;
					break;
				case 1 :
					cout << "A call on Tuesday starting at " << timeHour << ":00 and lasting for " << minutes << " minutes costs $" << cost << "." << endl;
					break;
				case 2 :
					cout << "A call on Wednesday starting at " << timeHour << ":00 and lasting for " << minutes << " minutes costs $" << cost << "." << endl;
					break;
				case 3 :
					cout << "A call on Thursday starting at " << timeHour << ":00 and lasting for " << minutes << " minutes costs $" << cost << "." << endl;
					break;
				case 4 :
					cout << "A call on Friday starting at " << timeHour << ":00 and lasting for " << minutes << " minutes costs $" << cost << "." << endl;
					break;
				case 5 :
					cout << "A call on Saturday starting at " << timeHour << ":00 and lasting for " << minutes << " minutes costs $" << cost << "." << endl;
					break;
				case 6 : 
					cout << "A call on Sunday starting at " << timeHour << ":00 and lasting for " << minutes << " minutes costs $"  << cost << "." << endl;
					break;
				default :
					cout << "Something went wrong. Please try the program again." << endl;
					break;
			}
		} else {
			switch (dayValue) {
				case 0 :
					cout << "A call on Monday starting at " << timeHour << ":" << timeMinutes << " and lasting for " << minutes << " minutes costs $" << cost << "." << endl;
					break;
				case 1 :
					cout << "A call on Tuesday starting at " << timeHour << ":" << timeMinutes << " and lasting for " << minutes << " minutes costs $"<< cost << "." << endl;
					break;
				case 2 :
					cout << "A call on Wednesday starting at " << timeHour << ":" << timeMinutes << " and lasting for " << minutes << " minutes costs $"<< cost << "." << endl;
					break;
				case 3 :
					cout << "A call on Thursday starting at " << timeHour << ":" << timeMinutes << " and lasting for " << minutes << " minutes costs $"<< cost << "." << endl;
					break;
				case 4 :
					cout << "A call on Friday starting at " << timeHour << ":" << timeMinutes << " and lasting for " << minutes << " minutes costs $" << cost << "." << endl;
					break;
				case 5 :
					cout << "A call on Saturday starting at " << timeHour << ":" << timeMinutes << " and lasting for " << minutes << " minutes costs $"<< cost << "." << endl;
					break;
				case 6 :
					cout << "A call on Sunday starting at " << timeHour << ":" << timeMinutes << " and lasting for " << minutes << " minutes costs $"<< cost << "." << endl;
					break;
				default :
					cout << "Something went wrong. Please try the program again." << endl;
					break;
			}
		}
		cout << "Do you want to use the program again? Press Y if yes : " << endl;
		cin >> programLoop;
	} while (programLoop == 'Y' || programLoop == 'y');
	return 0;
}
