// Domenico D'Erasmo
// 9 November 2017
// Code to test substring behavior

#include <iostream>
#include <string>

int main() {
	std::string testString = "hello";
	char testChar = testString.substr (1,1);
	std::cout << testChar << std::endl;
	return 0;
}
