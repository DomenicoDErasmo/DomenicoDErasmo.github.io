// Domenico D'Erasmo
// 14 September 2017
// Slope Program

#include <iostream>
using namespace std;

int main(){
	//variables
	double x1, x2, y1, y2, slope;
	
	//input
	cout << "The slope formula is (y2-y1)/(x2-x1)." << endl;
	cout << "Enter x2." << endl;
	cin >> x2;
	cout << "Enter x1." << endl;
	cin >> x1;
	cout << "Enter y2." << endl;
	cin >> y2;
	cout << "Enter y1." << endl;
	cin >> y1;

	//processing
	slope = (y2-y1)/(x2-x1);

	//output
	cout << "The slope for the points (" << x1 << "," << y1 << ")" << "and (" << x2 << "," << y2 << ") is " << slope << "." <<  endl;
	return 0;
}
