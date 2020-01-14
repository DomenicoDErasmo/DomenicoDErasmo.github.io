/* Working with arrays and functions
 * Author: Domenico D'Erasmo 
 * Last modified on: 18 January 2018
 * Known bug
 */ 
#include <iostream>

const int CAPACITY = 20;

//ToDo: Declare a function that displays the content of an int array, both the array and 
//   the size of array will be passed as parameters to the function 
void displayArray (int integerArray[], int arraySize);


//TODO: Declare a function that searches for a value in a given int array, it returns 
// -1 if the value does not occur in the array; if the value occurs in the array,
// the function returns the index of its first occurance. 
void arraySearch (int integerArray[], int arraySize, int query);

//TODO: Declare a function that deletes the element stored in a specified position from the array
int deleteElement (int integerArray[], int arraySize, int index);

/* 
  inserts a value into a given position in an array of int
   if the given position is occupied, that number and its subsequent numbers will
   shifted to the right of the array.  
  @param array: the int array that the value is to be inserted into
  @param array_size: the current size of the array. Upon successful 
                    insertion, the array_size will be increased by 1 
  @param value: the value to be inserted 
  @param index: the value is supposed to be inserted into the given index 
  @return -1 if the array is already full, cannot insert a new value
          otherwise, return the index of the new value in the array
  @precondition: index is less than array_size 
 */ 

int insertValueIntoArray (int integerArray[], int & arraySize, int value, int index); 

// appends the value
int appendIntoArray (int integerArray[], int & arraySize, int value);

// TODO: Declare a function that swaps two integer values. Use call-by-reference.
int swapIntegers (int& firstValue, int& secondValue);


// BONUS: Declare a function that swaps two integer values using pointers.


// TODO: Declare a function that reverses an array.
int reverseArray (int integerArray[], int arraySize);

// Displays the array whenever necessary
void displayArray (int integerArray[], int arraySize);

int main()
{
	// As the integerArray can be partially filled, we use variable integerArraySize to keep track of how many numbers
	// have been stored in the array. 
	int integerArray[CAPACITY] = {0};	// a int array with a given capacity
	int arraySize=0;  			// the array is initially empty, i.e., contains 0 elements
	int value, index;			// these are arguments for one of the necessary functions

	// 1. TODO: 	Prompt the user to enter a sequence of integer values, separated by space, and ended with -1,
	//		and store the values in the array 
	//		Display the array afterwards 
	
	std::cout << "Enter all of the array values, separated by spaces, and ending with -1.\n";
	
	do 
	{
		std::cin >> integerArray[arraySize];
		arraySize++;
	} while ((integerArray[arraySize - 1] != -1) && (arraySize < CAPACITY));
	

	if (integerArray[arraySize - 1] == -1) 
	{
		integerArray[arraySize - 1] = 0;	// prevents -1 from being stored in the array
	}
	
	arraySize --;					// prevents last 0 from being included

	displayArray (integerArray, arraySize);

	// 2. TODO: Call your function to search for value 50. 
	arraySearch (integerArray, arraySize, 50);
	displayArray (integerArray, arraySize);

	// 3. Call your function to append a value (entered by the user) to the array 
	//       Display the content of the array afterwards 
	std::cout << "Enter a value to append into the array : ";
	std::cin >> value;

	appendIntoArray (integerArray, arraySize, value);
	displayArray (integerArray, arraySize);
	

  // 4. Call your function to insert a value (entered by the user) to a given position (entered by the user) 
  // of the array 
  //       Display the content of the array afterwards 
  
	std::cout << "Enter a value to append into the array : ";
	std::cin >> value;
	std::cout << "Enter an index to append the value to : ";
	std::cin >> index;

	insertValueIntoArray (integerArray, arraySize, value, index);
	displayArray (integerArray, arraySize);

	
  // 5. Call your function to delete the values stored in position 0 and 2
  // Display the content of the array after the deletion. 
	
	std::cout << "The first and fourth values of the array (indices 0 and 3) will be deleted. \n";
  	
	deleteElement (integerArray, arraySize, 0);
	deleteElement (integerArray, arraySize, 3);
	displayArray (integerArray, arraySize);

  // 6. Call your function to reverse the array.
	
	reverseArray (integerArray, arraySize);
	displayArray (integerArray, arraySize);

  // 7. As a bonus, modify your reverse function to use the pointer version of swap.
	// I skipped this
	
	return 0;
}


//TODO: Implement all functions 

void displayArray (int integerArray[], int arraySize) 
{
	int loopIndex;
	std::cout << "The array is : \n";
	
	for (loopIndex = 0; loopIndex < arraySize; loopIndex++) 
	{
		std::cout << integerArray[loopIndex] << " ";
	}

	std::cout << "\n";
}

void arraySearch (int integerArray[], int arraySize, int query) 
{
	int loopIndex;
	bool returnFlag = true;

	for (loopIndex = 0; loopIndex < arraySize; loopIndex++) 
	{
		if (integerArray[loopIndex] == query) 
		{
			std::cout << query << " was found at position " << loopIndex << ".\n";
			returnFlag = false;
		}
	}

	if (returnFlag) 
	{
		std::cout << "-1 (" << query << " not found) \n";
	}
}

int insertValueIntoArray (int integerArray[], int& arraySize, int value, int index) 
{
	int loopIndex = arraySize + 1;

	if (index < arraySize)
	{
		if (arraySize < CAPACITY)
		{
			while (index <= loopIndex)
			{
				integerArray[loopIndex] = integerArray[(loopIndex - 1)];
				loopIndex--;
			} 

			integerArray[index - 1] = value;
			arraySize++;
		}
	}
	
	return 0;	
}

int appendIntoArray (int integerArray[], int& arraySize, int value) 
{
	arraySize++;
	integerArray[arraySize - 1] = value;
	return 0;
}

int deleteElement (int integerArray[], int arraySize, int index) 
{
	integerArray[index] = 0;
	return 0;
}

int reverseArray (int integerArray[], int arraySize) 
{
	int temp, loopIndex;
	
	arraySize--;	// this makes this code work and I'm too lazy to go back and change it to save on # of statements
	for (loopIndex = arraySize; loopIndex > ((arraySize + 1) / 2); loopIndex--) 
	{
		temp = integerArray[loopIndex];
		integerArray[loopIndex] = integerArray[arraySize - loopIndex];
		integerArray[arraySize - loopIndex] = temp;
	}
	return 0;
}
