// Domenico D'Erasmo
// 27 November 2017
// Program that uses arrays

#include <iostream>

int main()
{
	// variables
	int inputIndex, outputCounter, totalCounter;
	double grades[100], terminateCheck, total = 0, average;
	
	// initialize and input
	for (inputIndex = 0; inputIndex < 100; inputIndex++) 
	{
		grades[inputIndex] = 0;

		std::cout << "Enter a student grade (0-100) : ";
		std::cin >> terminateCheck;

		if ((terminateCheck >= 0) && (terminateCheck <= 100))
		{
			grades[inputIndex] = terminateCheck;
		}
 		else 
		{
			break;
		}
	}
	
	// processing and output
	for (outputCounter = 0; outputCounter < inputIndex; outputCounter ++)
	{
		total = total + grades[outputCounter];
		
	}
	
	average = total/(outputCounter);
	std::cout << "The average of the grades was " << average << ".\n";

	return 0;
}
