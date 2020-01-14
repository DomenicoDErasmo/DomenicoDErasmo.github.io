// Domenico D'Erasmo
// 16 October 2017
// Classwork
// Program to solve riddle of:
// odd #
// sum of digits is 27
// 1000's place is 3x that of 10's place
// all digits are different numbers

#include <iostream>

int main() {
	
	// variables
	int number, thousands, hundreds, tens, ones;

	// processing
	for (number = 1000; number <= 9999; number++){
		thousands = number/1000;					// thousands place
		hundreds = (number/100) - (thousands*10);			// hundreds place
		tens = (number/10) - (thousands*100) - (hundreds*10); 		// tens place
		ones = number - (thousands*1000) - (hundreds*100) - (tens*10);	// ones place
		if ((number % 2 == 0) && ((thousands + hundreds + tens + ones) == 27) && ((3*tens) == thousands) && ((thousands != hundreds) && (thousands != tens) && (thousands != ones) && (hundreds != tens) && (hundreds != ones) && (tens != ones))) {
			std::cout << number << " fits the criteria.\n";		// output
		} 
	}
	return 0;
}
