// Domenico D'Erasmo
// 28 February 2018
// Lab #5

#include <iostream>
#include <assert.h>
// Removed namespace for clarity of function origin

//Define a struct type, each struct type variable has three 
// member variables: array, capacity, and length. Together these
// three variables represent a partially filled array.
struct Array {
	int * array;  // point to the dynamically allocated array 
	int capacity; // the capacity of the array 
	int length;	// the number of elements in the array 
			// the array is filled from 0th, 1st, ... (length-1)-th
			// spots 
};


/* Initialize the array structure with the given numbers.
 * the array's capacity will be twice the length of numbers array 
 @param array: the array struct to be initialized
 @param numbers: the array of values to be stored in the array struct
 @param numbers_len: how many numbers are there in the array numbers
 precondition: "numbers" has been filled with "numbers_len" number of ints
 post condition: a.length == numbers_len
                 a.array[0]==numbers[0],..., 
		 a.capacity = 2*numbers_len
*/
void InitArray (Array & a, int numbers[], int numbers_len); 

/* Displays the content of an int array, both the array and 
   the length of array will be passed as parameters to the function 
   @param array: gives the array to be displayed
*/
void DisplayArray (const Array & a);

//Extra Credit Part: Implement this function, and test in main 
/* Read a sequence of int from input, and store them in the given Array 
 *  variable; we overwrite any existing content of the Array variable
 @param array: the Array variable that is used to store the numbers
 Note: you should allow the user to enter any many numbers as they want,
 the number sequence will be ended with a special value of -1 
 This means that you have to "grow" your array variable when needed 
*/
void InitArrayFromInput (Array & a); 

/* Merge the contents of two arrays into one
 @param array1: the target array
 @param array2: the source array
 @precondition: array1 and array2 have been set up 
 @postcondition: array1.length = array1.length+array2.length;
                 array1 contains its previous numbers, followed by numbers
		from array2 
 Note: if array1's capacity is not enough to hold all numbers, 
   you need to allocate a new int array, and copy old data over to the 
   new array... 
*/
void MergeArray (Array & a1, const Array & a2);



int main()
{
	// Variables
	int numbers1[5]={12, 23,34,56,78};
	int numbers2[11]={89, 7,14,22,98, 101, 112, 34, 11, 5, 99};
	
	// Default Init
	Array NumArray1={NULL,0,0};	//Declare a Array variable, and initilize its member variables 
	Array NumArray2={NULL,0,0};	//Declare another Array variable, and initialize its member variables 
	Array NumArray3={NULL,0,0};

	// Default Array Output
	std::cout << "***** NumArray1:\n";
	DisplayArray(NumArray1);
	std::cout << "***** NumArray2:\n";
	DisplayArray(NumArray2);
	std::cout << "***** NumArray3:\n";
	DisplayArray(NumArray3);

	// Initialize to given values
	InitArray (NumArray1, numbers1, 5);	//Now initialize the two Array variables with numbers from two static arrays
	InitArray (NumArray2, numbers2, 11);
	
	// Initialize third array with user input
	InitArrayFromInput(NumArray3);
	std::cout << NumArray3.length << std::endl;

	// Initialized Output
	std::cout << "***** NumArray1:\n";
	DisplayArray(NumArray1);

	std::cout << "***** NumArray2:\n";
	DisplayArray(NumArray2);

	std::cout << "***** NumArray3:\n";
	DisplayArray(NumArray3);

	// Merge Arrays
	MergeArray (NumArray1, NumArray2);
	
	// Output
	std::cout << "***** After merge:\n";
	std::cout << "***** NumArray1:\n";
	DisplayArray(NumArray1);

	std::cout << "***** NumArray3:\n";
	DisplayArray(NumArray3);
} 

// Initiates an array from user input
void InitArrayFromInput (Array & a)
{
	// variables
	int userInput, size = 0, loopIndex, capacity=10;
	int* tempArray;

	// dynamically allocate array
	a.array = new int[capacity];

	do
	{
		// input
		std::cout << "Enter a value into the array : ";
		std::cin >> userInput;

		// checks if -1 has been reached
		if (userInput == -1)
		{
			a.length = size;
			a.capacity = capacity;
			return;
		}

		if (size < capacity)
		{
			a.array[size] = userInput;
		}

		// creates a new array of double size for a.array, creating and deleting temporary arrays when needed
		else if (size >= capacity)
		{
			capacity = capacity*2;
			tempArray = new int[capacity];
			for (loopIndex = 0; loopIndex < capacity; loopIndex++)
			{
				tempArray[loopIndex] = a.array[loopIndex];
			}
			delete[] a.array;
			a.array = new int[capacity];
			for (loopIndex = 0; loopIndex < capacity; loopIndex++)
			{
				a.array[loopIndex] = tempArray[loopIndex];
			}
			delete[] tempArray;
		}
		size++;
	} 
	while (userInput != -1);
}

// Displays content of given array
void DisplayArray (const Array & a)
{
	// varaible
	int loopIndex;
	for (loopIndex = 0; loopIndex < a.length; loopIndex++)
	{
		std::cout << a.array[loopIndex] << " ";
	}
	std::cout << "\n" << "The length of the array is " << loopIndex << ".\n";
}

// Initialize the array structure with the given numbers.
// the array's capacity will be twice the length of numbers array 

void InitArray (Array & a, int numbers[], int numbers_len)
{
	// 1. Dynamically allocate an int array of size given by numbers_len*2
	//    and stores its address in a.array
	//    Set a.capacity 
	a.capacity = 2*numbers_len;
	a.array = new int[a.capacity];
	
	// 2. Copy the int numbers from array numbers to a.array
   	for (int loopIndex = 0; loopIndex < numbers_len; loopIndex++)
	{
		a.array[loopIndex] = numbers[loopIndex];
	}
	// 3. set a.length 
	a.length = numbers_len;
}

void MergeArray (Array & a1, const Array & a2)
{
	if (a1.length + a2.length > a1.capacity)
	{	//If a1.array is not big enough to hold all data 
     
		//1. Allocate a new dynamic int array that is big enough
		//   you can make its size be a1.length+a2.length+10 
		int newArrayCapacity = (a1.length + a2.length + 10);
		int * newArray = new int[newArrayCapacity];

		// 2. copy numebrs from a1.array to this new array 
		for (int loopIndex = 0; loopIndex < a1.length; loopIndex++)
		{
			newArray[loopIndex] = a1.array[loopIndex];
		}

		// 3. free the current a1.array 
		delete[] a1.array;

		//4. make a1.array points to the new array 
  		a1.array = newArray;

		//5. set a1.capacity to the new array's capacity
		a1.capacity = newArrayCapacity;
	}

	//Todo: append a2.array's data into a1.array  
	for (int loopIndex = 0; loopIndex < a2.length; loopIndex++)
	{
		a1.array[a1.length+loopIndex] = a2.array[loopIndex];
	}

	//Todo: update a1.length 
	a1.length = a1.length + a2.length;
}
