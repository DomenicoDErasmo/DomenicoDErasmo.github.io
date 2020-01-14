// Domenico D'Erasmo
// 14 September 2017
// Meeting Regulation

#include <iostream>
using namespace std;

int main(){
	// variables
	int capacity, attending;

	//input and storage
	cout << "How many people will be attending the meeting?" << endl;
	cin >> attending;
	cout << "What is the maximum room capacity?" << endl;
	cin >> capacity;
	
	//conditions and output
	if (capacity > attending) {
		cout << "The meeting can be held. " << capacity-attending << " more people can attend the meeting." << endl;
	} else if (capacity == attending) {
		cout << "The meeting can be held, but no one else may attend it." << endl;
	} else cout << "The meeting can't be held. There are " << attending-capacity << " too many people invited." << endl;
	return 0;
}
