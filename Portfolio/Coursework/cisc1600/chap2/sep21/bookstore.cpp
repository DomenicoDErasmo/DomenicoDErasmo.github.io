//  Domenico D'Erasmo
//  21 September 2017
//  Bookstore Code

#include <iostream>
using namespace std;

int main() {
	// initializes decimal format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// variables
	int cervantes, homer, shakespeare;
	string name;
	double pay, total, change, subtotal;

	// output and variable storage
	cout << "Welcome to the Bronx Bookstore! What is your first name? ";
	cin >> name;
	cout << "How many copies of Cervantes do you want? ";
	cin >> cervantes;
	cout << "How many copies of Homer do you want? ";
	cin >> homer;
	cout << "How many copies of Shakespeare do you want? ";
	cin >> shakespeare;
	subtotal = (41.25*cervantes)+(15.85*homer)+(30.50*shakespeare);
	total = subtotal*1.1;
	cout << "The total cost of the order is " << total << "." << endl << "How much will you pay? ";
	
	// processing and receipt
	cin >> pay;
		if(pay>=total) {
			change = pay-total;
			cout << "--------" << endl; 
			cout << "Customer: " << name << endl; 
			cout << "--------" << endl; 
			cout << "Item\t\tNumber\tPrice" << endl;
			cout << "Cervantes\t" << cervantes<< "\t" << "$" << cervantes*41.25<< endl;
			cout << "Homer\t\t" << homer << "\t" << "$" << homer*15.85 << endl;
			cout << "Shakespeare\t" << shakespeare << "\t" << "$" << shakespeare*30.50 << endl;
			cout << "--------" << endl;
			cout << "Tax\t\t\t$" << total-subtotal << endl;
			cout << "--------" << endl;
			cout << "Total\t\t\t$" << total << endl;
			cout << "User Pay\t\t" << pay << endl;
			cout << "--------" << endl;
			cout << "Change\t\t\t" << change << endl;
		} else cout << "You did not pay enough money. Goodbye" << endl;
	return 0;
}
