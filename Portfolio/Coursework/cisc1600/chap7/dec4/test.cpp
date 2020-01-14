// Domenico D'Erasmo
// 5 November 2017
// Test on character arithmetic

#include <iostream>

int main () {
	char letters[26];
	int loopIndex;

	for (loopIndex = 0; loopIndex < 26; loopIndex++) {
		letters[loopIndex] = 'a' + loopIndex;
		std::cout << letters[loopIndex] << "\n";
	}
	return 0;
}
