// Domenico D'Erasmo
// 11 February 2017
// Lab 3
// Lab Network

#include <iostream>

// prototyped functions
void userInput(int& numberOfLabs, int*& labStationSize, int**& labStation);
void displayStatus (int numberOfLabs, int* labStationSize, int** labStation, bool& redoCheck);
void simulateLogin (int numberOfLabs, int* labStationSize, int** labStation, bool& redoCheck);
void simulateLogoff (int numberOfLabs, int* labStationSize, int** labStation, bool& redoCheck);
void searchLabs (int numberOfLabs, int* labStationSize, int* labStation, bool& redoCheck);

int main()
{	
	// typedefs for clarity
	typedef int* integerPointer;		// I could use a global typedef instead of typing it in relevant functions for
	typedef int** integerDoublePointer;	// convenience, but I don't want to form suboptimal habits
	
	// variables
	integerPointer labStationSize;
	integerDoublePointer labStation;
	int numberOfLabs;
	bool redoCheck = true;

	// prompts user for the number of labs and stations at each lab
	userInput (numberOfLabs, labStationSize, labStation);
	
	do 
	{	
		// generates an interface for the user
		displayStatus (numberOfLabs, labStationSize, labStation, redoCheck);
	} 
	while (redoCheck);
	
	return 0;
}

// creates an ID at a lab and computer
// uses the number of labs, the array for size of each lab, the lab station array, 
// and a redoCheck that keeps displayStatus working continuously until prompted otherwise
void simulateLogin (int numberOfLabs, int* labStationSize, int** labStation, bool& redoCheck)
{
	// variables
	int labInput, stationInput, identificationNumber;
	bool labInputCheck = true, stationInputCheck = true, identificationNumberCheck = true;

	// the do-while loops prompt the user for input and prevent unwanted values that would cause core dumping
	do 
	{
		std::cout << "What lab is the student logging in at? ";
		std::cin >> labInput;
		if ((labInput > 0) && (labInput <= numberOfLabs))
		{
			labInputCheck = false;
		}
		else
		{
			std::cout << "That lab does not exist. Please try again.\n";
		}
	} 
	while (labInputCheck);
	
	do 
	{
		std::cout << "What station of lab " << labInput << "  is the student logging in at? ";
		std::cin >> stationInput;
		if ((stationInput > 0) && (stationInput <= (labStationSize[labInput - 1])))
		{
			stationInputCheck = false;
		}
		else
		{
			std::cout << "That station does not exist. Please try again.\n";
		}
	} 
	while (stationInputCheck);
	
	do 
	{
		std::cout << "What is the student's ID? ";
		std::cin >> identificationNumber;
		if ((identificationNumber >= 10000) && (identificationNumber <= 99999))
		{
			identificationNumberCheck = false;
		}
		else
		{
			std::cout << "That ID does not exist. Please try again.\n";
		}
	} 
	while (identificationNumberCheck);

	labStation[labInput - 1][stationInput - 1] = identificationNumber;
	std::cout << std::string (50,'\n');
}

// removes the ID from the array
// uses the same arguments as simulateLogin
void simulateLogoff (int numberOfLabs, int* labStationSize, int** labStation, bool& redoCheck) 
{
	// variables
	int labInput, stationInput;
	bool labInputCheck = true, stationInputCheck = true;

	// the two do-while loops prompt for input and prevent core dumping from values not in the array
	do 
	{
		std::cout << "What lab is the student logging off from? ";
		std::cin >> labInput;
		if ((labInput > 0) && (labInput <= numberOfLabs))
		{
			labInputCheck = false;
		}
		else
		{
			std::cout << "That lab does not exist. Please try again.\n";
		}
	} 
	while (labInputCheck);
	
	do 
	{
		std::cout << "What station of lab " << labInput << "  is the student logging off from?";
		std::cin >> stationInput;
		if ((stationInput > 0) && (stationInput <= labStationSize[labInput - 1]))
		{
			stationInputCheck = false;
		}
		else
		{
			std::cout << "That station does not exist. Please try again.\n";
		}
	} 
	while (stationInputCheck);
	
	labStation[labInput - 1][stationInput - 1] = 0;
	std::cout << std::string (50,'\n');
}

// searches for an ID and returns the lab number and station number
// uses the same arguments as the previous two functions
void searchLabs (int numberOfLabs, int* labStationSize, int** labStation, bool& redoCheck)
{
	// variables
	int loopIndex, loopIndexTwo, identificationNumber;
	bool foundCheck = true;

	// input - didn't check for specific values because arrays aren't being accessed
	std::cout << "What ID are you searching for? ";
	std::cin >> identificationNumber;

	for (loopIndex = 0; loopIndex < numberOfLabs; loopIndex++)
	{
		for (loopIndexTwo = 0; loopIndexTwo < labStationSize[loopIndex]; loopIndexTwo++)
		{
			if (labStation[loopIndex][loopIndexTwo] == identificationNumber)
			{
				std::cout << std::string(50,'\n');
				std::cout << identificationNumber << " was found at lab " << loopIndex + 1<< " station " << loopIndexTwo + 1<< ".\n";
				foundCheck = false;
				return;
			}
		}
	}

	if (foundCheck)
	{	
		std::cout << std::string(50,'\n');
		std::cout << identificationNumber << " was not found.\n";
	}
}

// gives the user a menu and options
void displayStatus (int numberOfLabs, int* labStationSize, int** labStation, bool& redoCheck) 
{
	// variables
	int loopIndex, loopIndexTwo, commandInput;
	
	// output - generates this text:
	// LAB STATUS:
	// Lab #	Computer Stations
	// 1		1: empty 2: empty 3: #####
	// 2		1: empty 2: #####
	// 3		1: ##### 2: empty 3: ##### 4: empty
	//
	// MAIN MENU
	// 0) Quit
	// 1) Simulate Login
	// 2) Simulate Logoff
	// 3) Search
	
	std::cout << "LAB STATUS:\n";
	std::cout << "Lab # \t Computer Stations\n";
	for (loopIndex = 0; loopIndex < numberOfLabs; loopIndex++) {
		std::cout << loopIndex + 1 << "\t ";
		for (loopIndexTwo = 0; loopIndexTwo < labStationSize[loopIndex]; loopIndexTwo++)
		{
			std::cout << loopIndexTwo + 1 << ": ";
			if ((labStation[loopIndex][loopIndexTwo] >= 10000) && (labStation[loopIndex][loopIndexTwo] <= 99999))
			{
				std::cout << labStation[loopIndex][loopIndexTwo] << " ";
			}
			else
			{
				std::cout << "empty ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	std::cout << "MAIN MENU \n";
	std::cout << "0) Quit \n";
	std::cout << "1) Simulate Login \n";
	std::cout << "2) Simulate Logoff \n";
	std::cout << "3) Search \n";
	std::cin >> commandInput;
	
	// branches off to different actions
	switch (commandInput) 
	{
		case 0 :
			redoCheck = false;
			break;
		case 1 :
			simulateLogin (numberOfLabs, labStationSize, labStation, redoCheck);
			break;
		case 2 :
			simulateLogoff (numberOfLabs, labStationSize, labStation, redoCheck);
			break;
		case 3 :
			searchLabs (numberOfLabs, labStationSize, labStation, redoCheck);
			break;
		default :
			std::cout << "You entered an invalid command. Please try again. \n";
			break;
	}		
}

// asks user to create the multidimensional array
void userInput(int& numberOfLabs, int*& labStationSize, int**& labStation) 
{
	//typedefs for clarity
	typedef int* integerPointer;
	typedef int** integerDoublePointer;
	
	// variables
	int loopIndex, loopIndexTwo;
	bool redoCheck, redoInputCheck = true;

	// input and check for invalid entries (less than 0)	
	do
	{
		std::cout << "How many labs are you managing? ";
		std::cin >> numberOfLabs;
		if (numberOfLabs < 1) 
		{
			std::cout << "Invalid entry. Please try again.\n";
		}
		else 
		{
			redoInputCheck = false;
		}
	}
	while (redoInputCheck);
	
	// labStationSize records the array size of each lab, labStation points to an array of pointers
	labStationSize = new int[numberOfLabs];
	labStation = new integerPointer[numberOfLabs];

	// input for each lab and input check
	for (loopIndex = 0; loopIndex < numberOfLabs; loopIndex++) 
	{
		redoCheck = true;
		do 
		{
			std::cout << "How many computers are in Lab " << loopIndex + 1 << "? ";
			std::cin >> labStationSize[loopIndex];
			if (labStationSize[loopIndex] < 0) 
			{
				std::cout << "An invalid number was entered. Please try again.\n";
			} 
			else
			{
				redoCheck = false;
			}
		} while (redoCheck);
		labStation[loopIndex] = new int [labStationSize[loopIndex]];
		for (loopIndexTwo = 0; loopIndexTwo < (labStationSize[loopIndex]); loopIndexTwo++) {
			labStation[loopIndex][loopIndexTwo] = 0;
		}
	}
	std::cout << std::string (50,'\n');
	std::cout << "Great! Initially, your lab computers' statuses are as follows : ";
}
