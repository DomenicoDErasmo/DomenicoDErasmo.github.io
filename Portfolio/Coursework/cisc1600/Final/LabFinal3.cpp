// Domenico D'Erasmo
// 20 December 2017
// Survey questioning

#include <iostream>

// prototyping
void issueInput(std::string issues[]);
void importanceInput(std::string issues[], double issueImportance[5][100], int& surveyNumber);
void outputResults (std::string issues[], double issueImportance[5][100], int surveyNumber);

int main() {

	// variables
	int surveyNumber = 1;
	std::string issues[5];
	double issueImportance[5][100], average;

	// input issues
	issueInput(issues);

	// input issue importance
	importanceInput(issues, issueImportance, surveyNumber);
	
	// output stats
	outputResults(issues, issueImportance, surveyNumber);
}

// input issues
void issueInput(std::string issues[]) {
	
	// variables
	int arraySize = 5, index;

	// input
	std::cout << "Enter 5 current issues to rate: \n";
	for (index = 0; index < arraySize; index++) {
		std::cout << "Enter topic (Politics, Economy, etc.) : ";
		std::cin >> issues[index];
	}
}

// input issue importance
void importanceInput(std::string issues[], double issueImportance[5][100], int& surveyNumber) {
	
	// variables
	std::string redoCheck;
	int issueIndex;

	// input
	do {
		std::cout << "Survey Entry #" << surveyNumber << "\n";
		std::cout << "Please rank the following issues on their importance to you, where 1 is least important and 10 is most important: \n";
		for (issueIndex = 0; issueIndex < 5; issueIndex++) {
			std::cout << issues[issueIndex] << ": ";
			std::cin >> issueImportance[issueIndex][surveyNumber - 1];
		}
		std::cout << "Do you want to take the survey again? (Yes or No): ";
		std::cin >> redoCheck;
		surveyNumber++;
	} while ((redoCheck == "Yes") || (redoCheck == "yes"));
	surveyNumber--;
}

// output results
void outputResults (std::string issues[], double issueImportance[5][100], int surveyNumber)  {
	
	// variables
	int outputHeaderIndex, sumIndex, issueIndex, averageIndex, outputBodyIndex, outputBodySurveyIndex;
	double sum[5] = {0}, average[5] = {0};

	// processing
	for (issueIndex = 0; issueIndex < 5; issueIndex++) {
		for (sumIndex = 0; sumIndex < surveyNumber; sumIndex++) {
			sum[issueIndex] += issueImportance[issueIndex][sumIndex];
		}
	}

	for (averageIndex = 0; averageIndex < 5; averageIndex++) {
		average[averageIndex] = (sum[averageIndex] / surveyNumber);
	}

	// output
	std::cout << "Results for " << surveyNumber << "Entries\n";
	std::cout << "Topics\t\tTotal\t\tAverage\t\t";
	for (outputHeaderIndex = 1; outputHeaderIndex <= surveyNumber; outputHeaderIndex++) {
		std::cout << "Entry #" << outputHeaderIndex << "\t";
	}
	std::cout << std::endl;
	for (outputBodyIndex = 0; outputBodyIndex < 5; outputBodyIndex++) {
		std::cout << issues[outputBodyIndex] << "\t\t" << sum[outputBodyIndex] << "\t\t" << average[outputBodyIndex];
		for (outputBodySurveyIndex = 0; outputBodySurveyIndex < surveyNumber; outputBodySurveyIndex++) {
			std::cout << "\t\t" << issueImportance[outputBodyIndex][outputBodySurveyIndex];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Goodbye!\n";
}
