/* Lab3: working with sorted array
 * Author: 
 * Last modifed on:
 * Known bug:
 * Note: Please use assert to check for precondtition */
#include <iostream>
#include <assert.h>
#include <vector>
#include <string>

const int CAPACITY=20;

/* Displays the content of a std::vector<std::string>,
   @param std::vector<std::string>: gives the std::vector<std::string> to be displayed
*/
void DisplayVector (std::vector<std::string> vstrings);


/*
  Binary search a vector of string for a given value, return true if found, false if not found 
  the index or would-be index of the value will be set to param index
   @param vstrings: gives the vector<string> to be displayed
   @param value: the value we are looking for 
   @param index: upon return, store the index of the occurence of the value (if found),
		or the would-be index of the value (if it's not found) 
   @precondition: vector contains vector.size() number of values in asceoding order 
   @postcondition: if value appeared in the array, its index is returned; otherwise -1 is returned 
*/
bool BinarySearch (std::vector<std::string> vstrings, std::string value, int & index);


/* 
 Deletes (i.e., removes) the element stored in the specified position from the SORTED vector, the 
 vector should be sorted afterwards
   @param vector: gives the vector to be deleted from
   @param index: we want to delete the {index}-th position in the vector 
   @precondition: vector contains vector.size() number of values in asceoding order 
        index < vector.size()
   @postcondition: if value stored in {index}-th position will be removed, the vector is still sorted. 
           vector.size() is decreased by 1
*/
void Delete (std::vector<std::string> & vstrings, int index);

/*
 * Deletes (i.e., removes) the element value by first searching for it and then deleting
 * if found. Uses BinarySearch(vector<string> vstrings, string value, int &index) to get
 * the index to pass into Delete(vector<string>, int index).
 * @param vector: gives the vector to be deleted from
 * @param string: we want to delete this value from the vector.
 * @precondition: vector contains vector.size() number of values in ascending order
 * @postcondition: if value is stored in vector, it will be removed, the vector will still be sorted.
 * 		vector.size() is decreased by 1.
 */
void Delete (std::vector<std::string>& vstrings, std::string value);


/* 
  inserts a value into an sorted vector so that the vector remains sorted,
  i.e., the value should be inserted before the first value that is 
  larger than it.  If the vector's content is "ann" "becky" "charlotte" "karen",
  and the value to be inserted into the vector is "julie", it should be put right
  before "karen", and the resulting vector should be "ann" "becky" "charolette"
  "julie" "karen" (assume all input is converted to lower case)
  @param vstrings: the vector that the value is to be inserted into
  @param value: the value to be inserted 
  @return: the index of the value in the vector 
  @precondition: vector.size() < vector.capacity() grow the vector 
  @postcondition: value is inserted into the vector, and the vector is sorted 
             vector.size() is incremented by 1.
 */ 
int InsertByValue (std::vector<std::string>& vstrings, std::string value);

void sortVector (std::vector<std::string>& another_vector);

int main()
{
 	// As the NumArray can be partially filled, we use variable NumArraySize to keep track of how many numbers have been stored in the array. 
	std::vector<std::string> vstrings;	// a string vector
	int vectorIndex;

	//1. Fill vector<string> with data in sorted order 
	// Display the array afterwards 
	// Create an sorted array 
	
	std::string temp_str;
	do 
	{
		std::cout << "Enter another name or -1 to end input: ";
		std::cin >> temp_str;
		if (temp_str != "-1") 
		{
			InsertByValue(vstrings, temp_str);
		}
 	} 
	while (temp_str != "-1");

	DisplayVector(vstrings);



	//2. TODO: Prompt the user to enter a value to search for, search for the value, and report the result 
	
	std::cout << "Enter a value to search for : ";
	std::cin >> temp_str;
 	if (BinarySearch (vstrings, temp_str, vectorIndex))
	{
		std::cout << temp_str << " was found at index " << (vectorIndex + 1) << ".\n";
	}
	else
	{
		std::cout << temp_str << " was not found in the vector.\n";
	}
	

	// 3. ToDo: Call your function to insert a value (entered by the user) into the vector
	// Display the content of the vector afterwards 
	
	std::cout << "Enter a string to insert into the vector : ";
	std::cin >> temp_str;
	InsertByValue(vstrings, temp_str);
	DisplayVector(vstrings);

	// 4. ToDo: Prompt the user to enter an index (for the value to be deleted), and then delete the elements stored there. 
	// Display the content of the vector after the deletion. 
	
	std::cout << "Enter a vector index to delete : ";
	std::cin >> vectorIndex;
	Delete (vstrings, vectorIndex);
	DisplayVector(vstrings);

	// 5. ToDo: Prompt the user to enter an value in the vector (to be deleted), and then delete the element 
	// Display the contents of the vector after the deletion.
	
	std::cout << "Enter a string from the vector to delete : ";
	std::cin >> temp_str;
	Delete (vstrings, temp_str);
	DisplayVector(vstrings);

	// BONUS: implement sorting vector.
 	
	std::vector<std::string> another_vector={"becky","ann","karen","julie", "frances"};
 
	//6. ToDo: call you sorting function to sort another_vector into ascending order 
	sortVector (another_vector);
	std::cout << "another_vector is sorted as : \n";
	DisplayVector(another_vector);

	return 0;
}


//TODO: Implement all functions, i.e., write the function definitions here ... 

/* Displays the content of a vector<string>,
   @param vector<string>: gives the vector<string> to be displayed
*/

void DisplayVector (std::vector<std::string> vstrings)
{
	// uses for-loop to iterate and display. BONUS: Use iterator vstrings.begin and vstrings.end
	for (std::vector<std::string>::iterator i =  vstrings.begin(); i != vstrings.end(); ++i) 
	{
		std::cout << *i << "\n";
	}
	std::cout << "\n";
}


/*
  Binary search a vector of string for a given value, return true if found, false if not found 
  the index or would-be index of the value will be set to param index
   @param vstrings: gives the vector<string> to be displayed
   @param value: the value we are looking for 
   @param index: upon return, store the index of the occurence of the value (if found),
		or the would-be index of the value (if it's not found) 
   @precondition: vector contains vector.size() number of values in ascending order 
   @postcondition: if value appeared in the array, its index is returned; otherwise -1 is returned 
*/

bool BinarySearch (std::vector<std::string> vstrings, std::string value, int & index)
{	
	// variables
	int searchCounter = 0, lowerBound = 0, upperBound = (vstrings.size() - 1), middleBound = (upperBound / 2);
	
	// binary sort, stops automatically after n tries, because the search if successful shouldn't take much longer than log2 n rounds to sort.
	do 
	{
		if (value == vstrings[middleBound])
		{
			index = middleBound;
			return true;
		}
		else if (value < vstrings[middleBound])
		{
			upperBound = middleBound;
			middleBound = ((lowerBound + middleBound) / 2);
		}
		else if (value > vstrings[middleBound])
		{
			lowerBound = middleBound;
			middleBound = ((middleBound + upperBound) / 2);
		}
		searchCounter++;
	} while (searchCounter < vstrings.size());
	return false;
}

/* 
 Deletes (i.e., removes) the element stored in the specified position from the SORTED vector, the 
 vector should be sorted afterwards
   @param vector: gives the vector to be deleted from
   @param index: we want to delete the {index}-th position in the vector 
   @precondition: vector contains vector.size() number of values in asceoding order 
        index < vector.size()
   @postcondition: if value stored in {index}-th position will be removed, the vector is still sorted. 
           vector.size() is decreased by 1
*/

void Delete (std::vector<std::string>& vstrings, int index)
{
	// keeps interface and vector index consistent
	index--;

	// uses vector.erase(index)
	vstrings.erase((vstrings.begin() + index));
}

/*
 * Deletes (i.e., removes) the element value by first searching for it and then deleting
 * if found. Uses BinarySearch(vector<string> vstrings, string value, int &index) to get
 * the index to pass into Delete(vector<string>, int index).
 * @param vector: gives the vector to be deleted from
 * @param string: we want to delete this value from the vector.
 * @precondition: vector contains vector.size() number of values in ascending order
 * @postcondition: if value is stored in vector, it will be removed, the vector will still be sorted.
 * 		vector.size() is decreased by 1.
 */

void Delete (std::vector<std::string>& vstrings, std::string value)
{
	// BinarySearch to get index and vector.erase(index) to delete.
	
	int index;
	BinarySearch(vstrings, value, index);

	// iterator to erase properly
	std::vector<std::string>::iterator vectorIndex = (vstrings.begin()+index);
	vstrings.erase(vectorIndex);
}


/* 
  inserts a value into an sorted vector so that the vector remains sorted,
  i.e., the value should be inserted before the first value that is 
  larger than it.  If the vector's content is "ann" "becky" "charlotte" "karen",
  and the value to be inserted into the vector is "julie", it should be put right
  before "karen", and the resulting vector should be "ann" "becky" "charolette"
  "julie" "karen" (assume all input is converted to lower case)
  @param vstrings: the vector that the value is to be inserted into
  @param value: the value to be inserted 
  @return: the index of the value in the vector 
  @precondition: vector.size() < vector.capacity() grow the vector 
  @postcondition: value is inserted into the vector, and the vector is sorted 
             vector.size() is incremented by 1.
 */
 
int InsertByValue (std::vector<std::string>& vstrings, std::string value)
{
	// Uses for-loop to find the vector entry that is greater than value
	// if we get to the end, do vector.push_back(value) otherwise use
	// vector.insert(vector.begin()+index, value);
	for (int loopIndex = 0; loopIndex < (vstrings.size()); loopIndex++)
	{
		if (vstrings[loopIndex] > value)
		{
			vstrings.insert (vstrings.begin() + loopIndex, value);
			return 0;
		}
	}
	vstrings.push_back(value);
}

// function to sort another_vector

void sortVector (std::vector<std::string>& another_vector)
{
	// variables
	int loopIndex, loopIndexTwo;
	std::string temp;

	for (loopIndex = 0; loopIndex < (another_vector.size()); loopIndex++)
	{
		for (loopIndexTwo = 0; loopIndexTwo < (another_vector.size());loopIndexTwo++)
		{
			if (another_vector[loopIndex] < another_vector[loopIndexTwo])
			{
				// swaps the two values
				temp = another_vector[loopIndex];
				another_vector[loopIndex] = another_vector[loopIndexTwo];
				another_vector[loopIndexTwo] = temp;
			}
		}
	}
}
