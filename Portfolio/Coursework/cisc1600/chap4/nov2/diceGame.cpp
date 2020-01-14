#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	// variables
	int index, roll, ranNumber;
	
	// initalization of time
	srand(time(0));
	
	// processing
	for (index=0; index < 5; index++) {
		ranNumber = rand();
		roll = (ranNumber % 6) + 1;
		std::cout << roll << "\n";
	}
	return 0;
}
