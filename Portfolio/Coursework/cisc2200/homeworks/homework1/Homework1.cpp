// Domenico D'Erasmo
// 4 September 2018
// Homework #1

#include <iostream>

int main()
{
	int value1 = 200, value2;
	
	// step 1 - Declare a variable intPtr to be a pointer to an object of type int.
	int* intPtr;

	// step 2 - Assign the address of variable value1 to pointer variable intPtr.
	intPtr = &value1;

	// step 3 - Print the value of the object pointed to by intPtr.
	std::cout << "The value of the object pointed to by intPtr is " << value1 << std::endl;

	// step 4 - Assign the value of the object pointed to by intPtr to variable value2.
	value2 = value1;

	// step 5 - Print the value of value2.
	std::cout << "Value of value2 : " << value2 << std::endl;
	
	// step 6 -  Print the address of value1.
	std::cout << "The address of value1 is : " << intPtr << std::endl;

	// step 7 - Print the address stored in intPtr. Is the value printed the same as value1's address?
	std::cout << "The address stored in intPtr is : " << intPtr << ". These values are the same." << std::endl;
	return 0;
}
