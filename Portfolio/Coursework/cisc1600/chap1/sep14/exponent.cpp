// Domenico D'Erasmo
// 14 September 2017
// Displays table of exponents

#include <iostream>
using namespace std;

int main()
{
	cout << "\t" << "a" << "\t" << "a^2" << "\t" << "a^3" << endl;  //Used \t to help format but I'd rather use printf than cout becuase it's so much more compact 
	for (int base=1; base<=7; base++){				//Used a for loop because I remember it being useful in my C class, and it saved time and code
		cout << "\t" << base << "\t" << base*base << "\t" << base*base*base << endl;
	}
	return 0;
}
