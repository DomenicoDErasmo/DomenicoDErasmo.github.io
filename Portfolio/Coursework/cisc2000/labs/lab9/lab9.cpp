// Domenico D'Erasmo
// April 20th, 2018
// Lab #9
#include <iostream>
#include "dnasequence.h"
#include <sstream>

// prompts the user for the type of input and what to input into the sequences
void sequencesInput (std::string& inputType, DNASequence*& sequences, int maxSequences);

// initializes DNASequences with file input
void consoleInput (DNASequence*& sequences, int maxSequences);


// creates big strand used in step #5
void createBigStrand (DNASequence*& sequences, int maxSequences, DNASequence& big_strand);

// initializes bad_dna
void badInput (DNASequence& bad_dna);

int main()
{
	// for looping program
	char redoCheck;

	// for dynamic allocation of DNASequences
	DNASequence* sequences;

	do
	{
		// maximum number of DNASequences
		int maxSequences;

		// initialized every loop to reset to false
		redoCheck = 'N';

		// used in step #5
		DNASequence big_strand;

		// prompt user for number of DNASequences
		std::cout << "How many DNA Sequences are needed for the CRISPR application? ";
		std::cin >> maxSequences;
		
		// for step #3
		sequences = new DNASequence[maxSequences];

		// for step #4
		consoleInput (sequences, maxSequences);
		
		// for step #5
		createBigStrand (sequences, maxSequences, big_strand);

		// for step #6
		std::cout << big_strand << "\n";
		
		// EXTRA CREDIT: for steps #7 - #12

		// DNASequences used in step #7 and #12
		DNASequence clean_strand = big_strand, bad_dna;
		
		// for step #8
		badInput (bad_dna);
		
		// for step #12
		std::cout << "For the overloaded % operator, big_strand becomes " << (big_strand % bad_dna) << ".\n";

		// for steps #9, #10, and #11
		std::cout << "For the overloaded - operator:\n";
		do
		{
			big_strand = clean_strand;
			clean_strand = big_strand - bad_dna;
			std::cout << "The clean strand is now " << clean_strand << ".\n";
		}
		while (clean_strand != big_strand);

		// prompts user for redo for step #14
		std::cout << "Would you like to use the program again? (Y/N): ";
		std::cin >> redoCheck;
	
		// for step #13 (numerous runs of program)
		delete[] sequences;
	}
	while ((redoCheck == 'Y') || (redoCheck == 'y'));
	
	std::cout << "Have a nice day!\n";
	return 0;
}

// allows for input through console
// takes two arguments:
// 	sequences is a pointer to an array of DNASequences called by reference
// 	maxSequences is the maximum number of sequences, defined at the start of the program
void consoleInput(DNASequence*& sequences, int maxSequences)
{
	// prompts and checks valid input 
	for (int loopIndex = 0; loopIndex < maxSequences; loopIndex++)
	{
		bool redoCheck = true;
		std::string input;
		do
		{
			std::cout << "Enter DNA Sequence " << loopIndex + 1 << ": ";
			std::cin >> input;
			if (sequences[loopIndex].get_validate(input))
			{
				redoCheck = false;
				std::stringstream checkedInput(input);
				checkedInput >> sequences[loopIndex];
			}
			else
			{
				std::cout << "Invalid data entered. Please try again.\n";
			}
		}
		while (redoCheck);
	}
}

// creates big_strand for step #5
// takes 3 arguments:
// 	sequences is the array of DNASequences
// 	maxSequences is the number of DNASequences in the array
// 	big_strand is the sequence created from all others
void createBigStrand (DNASequence*& sequences, int maxSequences, DNASequence& big_strand)
{
	for (int loopIndex = 0; loopIndex < maxSequences; loopIndex++)
	{
		big_strand  = big_strand + sequences[loopIndex];
	}
}

// creates bad_dna for step #8
void badInput (DNASequence& bad_dna)
{
	std::string input;
	std::cout << "Enter the bad DNA sequence: ";
	std::cin >> input;
	if (bad_dna.get_validate(input))
	{
		std::stringstream checkedInput (input);
		checkedInput >> bad_dna;
	}
}
