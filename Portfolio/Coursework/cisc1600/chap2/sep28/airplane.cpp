// Domenico D'Erasmo
// 28 September 2017
// Airplane ticket cost (Lab #4)

#include <iostream>
using namespace std;

int main() {

	// initializes decimal format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);	

	// variables 
	char destination, day;
	int miltimecheck, flighttype, daytype, miltimetype, miltime, ticketprice, tickets, cost; 
	int daycheck = 0, flightcheck = 0, ticketcheck = 0, paycheck = 0;
	double pay, change;
	
	// prompts and input checks
	cout << "Welcome to Fordham Airlines!" << endl;

	// check for valid destination (example: 'q' is not a valid destination)
	do {
		cout << "What is your destination? ([C]hicago, [M]iami, or [P]ortland) ";
		cin >> destination;
		switch (destination) {
			case 'c':
			case 'C':
				flightcheck++;
				flighttype = 1;
				break;
			case 'm':
			case 'M':
				flightcheck++;
				flighttype = 2;
				break;
			case 'p':
			case 'P':
				flightcheck++;
				flighttype = 3;
				break;
			default:
				cout << "That is not a valid type of day. Please try again." << endl;
		}

	} while (flightcheck == 0);

	// check for valid time (example: 1570 is not a time)
	do {
		cout << "Enter a flight time, in military time. ";
		cin >> miltime;
		miltimecheck = miltime % 100;
		if (miltimecheck >= 60 || miltime < 0 ||miltime > 2359){
			cout << "That is not a valid time. Please enter a valid time." << endl;
			miltimecheck = 60;
		} else if (miltime >= 500 || miltime <= 1900){
			miltimetype = 1;
		} else if ((miltime >= 0 && miltime < 500) || (miltime > 1900 || miltime < 2400)) {
			 miltimetype = 2;
		} else {
			cout << "That is not a valid time. Please enter a valid time. " << endl;
			miltimecheck = 60;
		} 
	} while (miltimecheck >= 60);
	
	// check for a valid day of week (example: 'r' is not a valid day of the week)
	do {
		cout << "What type of day would you like to travel? (week[D]ay or week[E]nd) ";
		cin >> day;
        	switch (day) {
			case 'd':
			case 'D':
				daycheck++;
				daytype = 1;
				break;
			case 'e':
			case 'E':
				daycheck++;
				daytype = 2;
				break;
			default:
				cout << "That is not a valid type of day. Please try again." << endl;
		}
	} while (daycheck == 0);

	// switch to determine ticket price
	switch (daytype) {
		case 1:
			switch (miltimetype) {
				case 1:
					switch (flighttype) {
						case 1:
							ticketprice = 75;
							break;
						case 2:
							ticketprice = 150;
							break;
						case 3:
							ticketprice = 300;
							break;
					}
				case 2:
					switch (flighttype) {
						case 1:
							ticketprice = 50;
							break;
						case 2:
							ticketprice = 100;
							break;
						case 3:
							ticketprice = 200;
							break;
						}
			}
		case 2:
			switch (miltimetype) {
				case 1:
					switch (flighttype) {
						case 1:
							ticketprice = 90;
							break;
						case 2:
							ticketprice = 180;
							break;
						case 3:
							ticketprice = 360;
							break;
					}
				case 2:
					switch (flighttype) {
						case 1:
							ticketprice = 60;
							break;
						case 2:
							ticketprice = 120;
							break;
						case 3:
							ticketprice = 240;
							break;
					}
			}
	}
	do {
		cout << "Each ticket costs $" << ticketprice << " . How many tickets would you like to buy? ";
		cin >> tickets;
		if (tickets > 1){
			ticketcheck ++;
			do {
				cost = ticketprice*tickets;
				cout << "Your total cost is $" << cost << ". How much would you like to pay? ";
				cin >> pay;
				if (pay >= cost) {
					change = pay-cost;
					cout << "Your order has been placed. Your change is $" << change << " . Have a nice day!" << endl;
					paycheck ++;
				} else { 
					change = cost-pay;
					cout << "You have not paid enough money. You were $" << change << " short. Please try again." << endl;
				}
			} while (paycheck == 0);
		} else cout << "You did not get any tickets. Please enter a number of tickets to buy." << endl;
	} while (ticketcheck == 0);
	return 0;
}
