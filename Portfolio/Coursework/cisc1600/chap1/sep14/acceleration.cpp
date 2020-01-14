// Domenico D'Erasmo
// 14 September 2017
// Acceleration Program

#include <iostream>
using namespace std;

int main(){
	//variables
	double startvelocity, endvelocity, time, acceleration;
	
	//input
	cout << "Enter the starting velocity. (m/s)" << endl;
	cin >> startvelocity;
	cout << "Enter the ending velocity. (m/s)" << endl;
	cin >> endvelocity;
	cout << "Enter the time passed. (s)" << endl;
	cin >> time;
	
	//processing
	acceleration = (endvelocity-startvelocity)/time;
	
	//output
	cout << "The accleration is " << acceleration << "(m/s^2)." << endl;
	return 0;
}
