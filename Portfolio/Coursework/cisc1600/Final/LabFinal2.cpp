// Domenico D'Erasmo
// 20 December 2017
// Code to calculate test score statistics

#include <iostream>

// prototyping
void statistics(int arrayMaxPosition, double& averageScore, int studentScore[], std::string studentName[]);

int main() {

	// initialize decimal format
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(2);
	
	// variables
	int studentScore[50] = {0}, arrayPosition, advanceCheck;
	double averageScore;
	std::string studentName[50];

	// input
	for (arrayPosition = 0; arrayPosition < 50; arrayPosition++) {
		std::cout << "Enter a test score : ";
		std::cin >> advanceCheck;
		if (advanceCheck == -1) {
			break;
		} else {
			studentScore[arrayPosition] = advanceCheck;
		}
		std::cout << "Enter a student name : ";
		std::cin >> studentName[arrayPosition];
	} 

	// processing (outsourced to function)
	statistics(arrayPosition, averageScore, studentScore, studentName);
	
	// output
	std::cout << "The minimum score is " << studentScore[0] << ", " << studentName[0] << "\n";
	std::cout << "The maximum score is " << studentScore[arrayPosition-1] << ", " << studentName[arrayPosition-1] << "\n";
	std::cout << "The average is " << averageScore << "\n";
	std::cout << "Have a nice day!\n";

	return 0;
}

void statistics(int arrayMaxPosition, double& averageScore, int studentScore[], std::string studentName[]) {
	
	// variables
	double sumScore = 0; 
	int averageIndex, cycleIndex, checkIndex, scoreSwap;
	std::string nameSwap;
	
	// sorts in descending order for max and min
	for (cycleIndex = 0; cycleIndex < arrayMaxPosition; cycleIndex++) {
		for (checkIndex = 0; checkIndex < arrayMaxPosition; checkIndex++) {
			if (studentScore[checkIndex] > studentScore[cycleIndex]) {
				scoreSwap = studentScore[checkIndex];
				nameSwap = studentName[checkIndex];
				studentScore[checkIndex] = studentScore[cycleIndex];
				studentName[checkIndex] = studentName[cycleIndex];
				studentScore[cycleIndex] = scoreSwap;
				studentName[cycleIndex] = nameSwap;
			}
		}
	}
	
	// calculates average
	for (averageIndex = 0; averageIndex < arrayMaxPosition; averageIndex++) {
		sumScore = sumScore + studentScore[averageIndex];
	}
	averageScore = sumScore / arrayMaxPosition;
}
