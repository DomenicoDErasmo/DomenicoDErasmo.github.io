// Domenico D'Erasmo
// 13 November 2017
// Code that uses call by value (copy of data)

#include <iostream>

void output(int&);

int main() {
	int callThis;
	callThis = 100;
	output(callThis);
	std::cout << "callThis = " << callThis << ".\n";
	return 0;
}

void output(int& calledByMain) {
	std::cout << "X = " << calledByMain << ".\n";
	calledByMain += 2;
	std::cout << "X = " << calledByMain << ".\n";
}
