#include <iostream>
 #include <string>
#include <cstring>
#include <cctype>
#include "dnasequence.h"

// removed using namespace std

// NOTE THIS
// 	If you can't find a way to set max_sequence_size to be the number of initaited characters + 1 (for null), then redo 
// 	comparisons involving two dna_sequences (may otherwise go out of bounds)

// Assume that the strand is made up of 20 sequences.
DNASequence::DNASequence() 
{
	max_sequence = 21;
	dna_sequence = new char[max_sequence];	
	dna_sequence[20] = '\0';
}

// Assume that the sequence is initialized to the nucleotides string.
DNASequence::DNASequence(std::string nucleotides) 
{
	max_sequence = nucleotides.length() + 1;
	dna_sequence = new char[max_sequence];
	for (int loopIndex = 0; loopIndex < max_sequence - 1; loopIndex++)
	{
		dna_sequence[loopIndex] = nucleotides.at(loopIndex);
	}
	dna_sequence[max_sequence] = '\0';
}

// Copy constructor
DNASequence::DNASequence(const DNASequence& arg)
{
	max_sequence = arg.max_sequence;
	dna_sequence = new char[max_sequence];
	for (int loopIndex = 0; loopIndex < max_sequence; loopIndex++)
	{
		dna_sequence[loopIndex] = arg.dna_sequence[loopIndex];
	} 
}

// Destructor
DNASequence::~DNASequence()
{
	delete[] dna_sequence;
}


// Assignment operator
DNASequence& DNASequence::operator=(const DNASequence& arg)
{
	// checks if the two sequences are the same
	if (this != &arg)
	{
		// creates a larger dna_sequence if more space is required
		if (max_sequence < arg.max_sequence)
		{
			delete[] dna_sequence;
			max_sequence = arg.max_sequence;
			dna_sequence = new char[max_sequence];
		}
		max_sequence = arg.max_sequence;
		for (int loopIndex = 0; loopIndex < max_sequence - 1; loopIndex++)
		{
			dna_sequence[loopIndex] = arg.dna_sequence[loopIndex];
		}
		dna_sequence[max_sequence] = '\0';
	}
	return *this;
}

// Equals operator compares the given sequence with the invoking object.
bool DNASequence::operator==(const DNASequence& arg)
{
	// compares dna_sequence size to make sure they are the same
	if (max_sequence == arg.max_sequence)
	{
		// checks that all characters are the same, returns false if any character differs, otherwise returns true
		for (int loopIndex = 0; loopIndex < max_sequence; loopIndex++)
		{
			if (dna_sequence[loopIndex] == arg.dna_sequence[loopIndex])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

// Not equals operator compares the given sequence with the invoking object.
bool DNASequence::operator!=(const DNASequence& arg)
{
	// compares dna_sequence size to check if they are the same, returns true if not the case
	if (max_sequence = arg.max_sequence)
	{
		// checks that all characters are the same, returns true if any character differs, otherwise returns false
		for (int loopIndex = 0; loopIndex < max_sequence; loopIndex++)
		{
			if (dna_sequence[loopIndex] != arg.dna_sequence[loopIndex])
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return true;
	}
}


// Append the given sequence onto the end of the invoking object sequence.
DNASequence operator+(const DNASequence& arg1, const DNASequence& arg2)
{
	// first loopIndex increments the first loop, while the second incrementes the second loop
	// declared two loop variables because in loop 2 one keeps track of the position in the 
	// 	result.dna_sequence char array while the other keeps track of the position in the 
	// 	arg2.dna_sequence char array
	int loopIndex, loopIndex2;

	// creates a DNASequence that is returned at the end of the operator
	DNASequence result = arg1;

	// sets up appropiate max_sequence size, uses a -1 becuase the added strings would give two null characters not one
	result.max_sequence = arg1.max_sequence + arg2.max_sequence - 1;

	// clear memory so that we can reassign result.dna_sequence
	delete[] result.dna_sequence;

	// reassign result.dna_sequence
	result.dna_sequence = new char[result.max_sequence];
	
	// initialize result.dna_sequence
	for (loopIndex = 0; loopIndex < arg1.max_sequence - 1; loopIndex++)
	{
		result.dna_sequence[loopIndex] = arg1.dna_sequence[loopIndex];
	}

	// picks up from end of arg1 and adds arg2
	for (loopIndex2 = 0; loopIndex2 < arg2.max_sequence; loopIndex2++)
	{
		result.dna_sequence[loopIndex] = arg2.dna_sequence[loopIndex2];
		loopIndex++;
	}
	result.dna_sequence[result.max_sequence] = '\0';
	return result;
}

// Remove the given sequence from the invoking object if it exists. Return
// 	the modified sequence. If the given sequence is not found, return the
// 	first argument sequence unaltered.
// const removed from arg1 to change arg1.max_sequence, allowing for repeated chains of the - operator
DNASequence operator-(DNASequence& arg1, const DNASequence& arg2)
{
	// plan:
	// 	1. set result = arg1
	// 	2. check if arg2.max_sequence > arg1.max_sequence, return default result if this is the case
	// 	3. loop through result.max_sequence - arg2.max_sequence + 1, search for 1st same letter (at outerLoopIndex)
	// 	4. declare before loop a flag to be true, make the flag false if not all match,
	// 	5. if first letter matches, then check that rest match (outerLoopIndex to (oLI + arg2.max_sequence - 1))
	// 	6. if flag is false, then go back to 1. but if flag is true, create a new array with arg2 removed
	// 	7. remove arg2 by:
	// 		a. set tempRestult = result
	// 		a. making result.max_sequence = tempResult.max_sequence (characters + null) - (arg2.max_sequence-1) (chars)
	// 		b. implement the tempResult characters before the position where the match occured (until outerLoopIndex)
	// 		c. implement the tempResult characters after the end of the match (loopIndex + arg2.max_sequence - 1)
	DNASequence result, tempResult;
	
	// step 1
	result.max_sequence = arg1.max_sequence;
	for (int initResultLoopIndex = 0; initResultLoopIndex < arg1.max_sequence; initResultLoopIndex++)
	{
		result.dna_sequence[initResultLoopIndex] = arg1.dna_sequence[initResultLoopIndex];
	}
	
	// step 2
	if (arg2.max_sequence > arg1.max_sequence)
	{
		return result;
	}
	
	// step 3 - end
	for (int outerLoopIndex = 0; outerLoopIndex < (result.max_sequence - arg2.max_sequence + 1); outerLoopIndex++)
	{
		// step 3
		if (result.dna_sequence[outerLoopIndex] == arg2.dna_sequence[0])
		{
			// step 4
			bool matchFlag = true;
			
			// step 5
			for (int sameLoopIndex = 0; (sameLoopIndex < arg2.max_sequence - 1); sameLoopIndex++)
			{
				if (result.dna_sequence[outerLoopIndex + sameLoopIndex] != arg2.dna_sequence[sameLoopIndex])
				{
					matchFlag = false;
				}
			}
			
			// step 6
			if (matchFlag)
			{
				// declared outside of loop becuase it is used in another
				int preLoopIndex;
				
				// step 7a - set tempResult = result
				tempResult.max_sequence = result.max_sequence;
				for (int initTempResultLoopIndex = 0; initTempResultLoopIndex < tempResult.max_sequence; initTempResultLoopIndex++)
				{
					tempResult.dna_sequence[initTempResultLoopIndex] = result.dna_sequence[initTempResultLoopIndex];
				}
				
				// step 7b - size of result
				result.max_sequence = result.max_sequence - (arg2.max_sequence - 1);
				
				// step 7c - pre-arg2
				for (preLoopIndex = 0; preLoopIndex < outerLoopIndex; preLoopIndex++)
				{
					result.dna_sequence[preLoopIndex] = tempResult.dna_sequence[preLoopIndex];
				}
				
				// step 7d - post-arg2
				for (int postLoopIndex = preLoopIndex; postLoopIndex < (tempResult.max_sequence); postLoopIndex++)
				{
					result.dna_sequence[postLoopIndex] = tempResult.dna_sequence[postLoopIndex + (arg2.max_sequence - 1)];
				}
				
				// adjusts size of arg1
				arg1.change_max_sequence(result.get_max_sequence());
				return result;
			}
			
		}
	}
	return result;
}

// To make the code compile, a function that validates the input string

// Remove all instance of the given sequence from the invoking object if it exists. Return
// the modified sequence. If the given sequence is not found, return the
// first argument sequence unaltered.
DNASequence operator%(const DNASequence& arg1, const DNASequence& arg2)
{
	// plan:
	// 	1. set result = arg1
	// 	2. check if arg2.max_sequence > arg1.max_sequence, return default result if this is the case
	// 	3. loop through result.max_sequence - arg2.max_sequence + 1, search for 1st same letter (at outerLoopIndex)
	// 	4. declare before loop a flag to be true, make the flag false if not all match,
	// 	5. if first letter matches, then check that rest match (outerLoopIndex to (oLI + arg2.max_sequence - 1))
	// 	6. if flag is false, then go back to 1. but if flag is true, create a new array with arg2 removed
	// 	7. remove arg2 by:
	// 		a. set tempRestult = result
	// 		a. making result.max_sequence = tempResult.max_sequence (characters + null) - (arg2.max_sequence-1) (chars)
	// 		b. implement the tempResult characters before the position where the match occured (until outerLoopIndex)
	// 		c. implement the tempResult characters after the end of the match (loopIndex + arg2.max_sequence - 1)
	// 	8. reset outerLoopIndex to chain the operation
	DNASequence result, tempResult;
	
	// step 1
	result.max_sequence = arg1.max_sequence;
	tempResult.max_sequence = arg1.max_sequence;

	for (int initResultLoopIndex = 0; initResultLoopIndex < arg1.max_sequence; initResultLoopIndex++)
	{
		result.dna_sequence[initResultLoopIndex] = arg1.dna_sequence[initResultLoopIndex];
	}
	
	// step 2
	if (arg2.max_sequence > arg1.max_sequence)
	{
		return result;
	}
	
	// steps 3 to 8
	for (int outerLoopIndex = 0; outerLoopIndex < (result.max_sequence - arg2.max_sequence + 1); outerLoopIndex++)
	{
		// step 3
		if (result.dna_sequence[outerLoopIndex] == arg2.dna_sequence[0])
		{
			// step 4
			bool matchFlag = true;
			
			// step 5
			for (int sameLoopIndex = 0; (sameLoopIndex < arg2.max_sequence - 1); sameLoopIndex++)
			{
				if (result.dna_sequence[outerLoopIndex + sameLoopIndex] != arg2.dna_sequence[sameLoopIndex])
				{
					matchFlag = false;
				}
			}
			
			// step 6
			if (matchFlag)
			{
				// declared outside of loop becuase it is used in another
				int preLoopIndex;
				
				// step 7a - set tempResult = result
				tempResult.max_sequence = result.max_sequence;
				for (int initTempResultLoopIndex = 0; initTempResultLoopIndex < tempResult.max_sequence; initTempResultLoopIndex++)
				{
					tempResult.dna_sequence[initTempResultLoopIndex] = result.dna_sequence[initTempResultLoopIndex];
				}
				
				// step 7b - size of result
				result.max_sequence = result.max_sequence - (arg2.max_sequence - 1);
				
				// step 7c - pre-arg2
				for (preLoopIndex = 0; preLoopIndex < outerLoopIndex; preLoopIndex++)
				{
					result.dna_sequence[preLoopIndex] = tempResult.dna_sequence[preLoopIndex];
				}
				
				// step 7d - post-arg2
				for (int postLoopIndex = preLoopIndex; postLoopIndex < (tempResult.max_sequence); postLoopIndex++)
				{
					result.dna_sequence[postLoopIndex] = tempResult.dna_sequence[postLoopIndex + (arg2.max_sequence - 1)];
				}
				// step 8 - reset outerLoopIndex to chain the operation
				outerLoopIndex = 0;
			}
			
		}
	}
	return result;
}

// To make the code compile, a function that validates the input string
// is made up purely of nucleotides.
bool DNASequence::validate(std::string str) {
	// Check the string for characters 'A', 'a', 'T', 't', 'G', 'g', 'C', 'c'
	// 	return false if any characters in the string are different. You can
	// 	use any means you like, remember what we did with palindrome code to
	// 	avoid a big if statement.
	for (int loopIndex = 0; loopIndex < str.length(); loopIndex++)
	{
		switch (str.at(loopIndex))
		{
			case 'A':
			case 'a':
			case 'T':
			case 't':
			case 'G':
			case 'g':
			case 'C':
			case 'c':
				break;
			default:
				return false;
				break;
		}
	}	
	return true;
}

// Implement the friend function to read in a nucleotide sequence made up
// of only the following characters: adenine (A), thymine (T), guanine (G)
// and cytosine (C). Assume case insensitive but convert to upper internally.
std::istream& operator>>(std::istream& ins, DNASequence& arg)
{
	// validate function used in main code to handle redos better
	// check is used as a buffer and its components are then assigned to the char array
	std::string check;
	if (ins >> check)
	{
		arg.max_sequence = check.size() + 1;
		for (int loopIndex = 0; loopIndex < arg.max_sequence - 1; loopIndex++)
		{
			// fromStream is taken from the istream
			char fromStream = check.at(loopIndex);
			fromStream = toupper (fromStream);
			arg.dna_sequence[loopIndex] = fromStream;
		}
	}
	arg.dna_sequence[arg.max_sequence - 1] = '\0';
	return ins;
}

// Implement the friend function to write out a nucleotide sequence. No blanks.
std::ostream& operator<<(std::ostream& out, const DNASequence& arg)
{
	for (int loopIndex = 0; loopIndex < arg.max_sequence - 1; loopIndex++)
	{
		out << arg.dna_sequence[loopIndex];
	}
	return out;
}

// Accessor for max_sequence
int DNASequence::get_max_sequence() const
{
	return max_sequence;
}

// Accessor for dna_sequence
char* DNASequence::get_dna_sequence() const
{
	return dna_sequence;
}

// Accessor for validate
bool DNASequence::get_validate(std::string input)
{
	return validate(input); 
}

// Mutator for max_sequence
void DNASequence::change_max_sequence (int input)
{
	max_sequence = input;
}

// Mutator for dna_sequence
void DNASequence::change_dna_sequence (std::string input)
{
	for (int loopIndex = 0; loopIndex < input.length(); loopIndex++)
	{
		dna_sequence[loopIndex] = input.at(loopIndex);
	}
}
