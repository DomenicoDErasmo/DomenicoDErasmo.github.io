// Domenico D'Erasmo
// 2 October 2017
// Program to calculate grade

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// variables
	int assignmentNumber, assignmentCounter;
	double score, maxScore, sumScore = 0, sumMax = 0, grade;
	
	// input
	cout << "How many exercises have you completed? " << endl;
	cin >> assignmentNumber;

	
	// loop to allow for entry of all grades
	for (assignmentCounter = 0; assignmentCounter < assignmentNumber; assignmentCounter++) {
		cout << "Score received for exercise " << assignmentCounter+1 << " : ";
		cin >> score;
		cout << "Total points possible for exercise " << assignmentCounter+1 << " : ";
		cin >> maxScore;
		sumScore = sumScore + score;
		sumMax = sumMax + maxScore;
	}

	// final output
	grade = sumScore*100/sumMax;
	cout << "Your total is " << sumScore << " out of " << sumMax << ", or " << setprecision(2) << fixed << grade << "%." << endl;
	return 0;
}
