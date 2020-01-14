// Domenico D'Erasmo
// 2 November 2017
// Variables in Side Functions Test

#include <iostream>

bool sizeCompare(int num1) {
	int num2 = 4;
	if (num1 >= num2) {
		return true;
	} else {
		return false;
	}
}
int main() {
	int num1, num2;
	std::cout << "Enter a number to compare : ";
	std::cin >> num1;
	if (sizeCompare(num1)) {
		std::cout << num1 << " is larger than or equal to 4.\n";
	} else {
		std::cout << num1 << " is smaller than 4.\n";
	}
	return 0;
}
