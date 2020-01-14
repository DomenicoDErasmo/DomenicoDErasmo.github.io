// Domenico D'Erasmo
// 17 January 2018
// Lab #1
// Calculates inflation rate given two Consumer Price Index values and prints it to monitor

// Libraries
#include <iostream>

// Prototyping functions
double inflationRate  (float oldConsumerPriceIndex, float newConsumerPriceIndex);
double calculateAverageInflation (float inflationArray[], int arrayIndex);
double calculateMedianInflation (float inflationArray[], int arrayIndex);

int main() {
	
	// TODO #1: declare two float variables for old CPI and new CPI
	float oldConsumerPriceIndex, newConsumerPriceIndex, inflationChange, averageInflation, medianInflation;
	float oldCPIArray[50] = {0}, newCPIArray[50] = {0}, inflationArray[50] = {0};
	char redoCheck;
	int arrayIndex = 0;
		
	// BONUS #1: Put the logic in TODO #2-4 in a loop that asks the user to enter 'y' if there's more data
	do {
		// TODO #2: read in two float values for the two CPIs and store them in the variables
		std::cout << "Enter the initial Consumer Price Index value : ";
		std::cin >> oldConsumerPriceIndex;
		std::cout << "Enter the new Consumer Price Index value : ";
		std::cin >> newConsumerPriceIndex;
		
		// TODO #3: call the function InflationRate with the two CPIs
		inflationChange = inflationRate (oldConsumerPriceIndex, newConsumerPriceIndex);
		
		// assigns variables to arrays for BONUS #2
		oldCPIArray[arrayIndex] = oldConsumerPriceIndex;
		newCPIArray[arrayIndex] = newConsumerPriceIndex;
		inflationArray[arrayIndex] = inflationChange;
		
		//calls function to calculate average for BONUS #2
		averageInflation = calculateAverageInflation (inflationArray, arrayIndex);
		
		// calls function to calculate median for BONUS #3
		medianInflation = calculateMedianInflation (inflationArray, arrayIndex);

		//TODO #4: print the results
		std::cout << "The inflation rate is " << inflationChange << "%.\n";
		std::cout << "The average inflation rate across the data is " << averageInflation << "%.\n";
		std::cout << "The median inflation rate across the data is " << medianInflation << "%.\n";
		std::cout << "Would you like to run the program again? (y/n) : ";
		std::cin >> redoCheck;
		
		// increments arrayIndex for next cycle
		arrayIndex++;

	} while ((redoCheck == 'y') || redoCheck == 'Y');

	std::cout << "Have a nice day!\n";

	return 0;
}

// double inflationRate (float oldConsumerPriceIndex, float newConsumerPriceIndex)
// precondition: both prices must be greater than 0.0
// postcondition: the inflation rate is returned or -1.0 for invalid inputs

double inflationRate (float oldConsumerPriceIndex, float newConsumerPriceIndex) {
	//TODO: Implement InflationRate to calculate the percentage increase or decrease
	//Use (new_cpi - old_cpi) / old_cpi * 100
	
	double inflationChange;
	
	// checks that both values of price index are greater than 0, and returns -1.0 if either fails this condition
	if ((oldConsumerPriceIndex > 0) && (newConsumerPriceIndex > 0)) {
		inflationChange = ((newConsumerPriceIndex - oldConsumerPriceIndex)/ oldConsumerPriceIndex) * 100;
		return inflationChange;
	} else {
		inflationChange = -1.0;
		return inflationChange;
	}
}

double calculateAverageInflation (float inflationArray[], int arrayIndex) {
	int loopIndex;
	float sum, average;

	// calculates the sum
	for (loopIndex = 0; loopIndex <= arrayIndex; loopIndex++) {
		sum = sum + inflationArray[loopIndex];
	}
	average = sum / loopIndex;
	return average;
}

double calculateMedianInflation (float inflationArray[], int arrayIndex) {
	int loopIndex, compareIndex;
	float temp, median;

	// uses two loops to sort the array elements in ascending order
	for (loopIndex = 0; loopIndex < arrayIndex; loopIndex++) {
		for (compareIndex = 0; compareIndex < arrayIndex; compareIndex++) {
			if (inflationArray[compareIndex] > inflationArray[loopIndex]) {
				temp = inflationArray[compareIndex];
				inflationArray[compareIndex] = inflationArray[loopIndex];
				inflationArray[loopIndex] = temp;
			}
		}
	} 

	if (arrayIndex % 2 == 0) {
		median = inflationArray[((arrayIndex + 1) / 2)];
	} else {
		median = (inflationArray[((arrayIndex - 1) / 2)] + inflationArray[((arrayIndex + 1) / 2)]) / 2;
	}

	return median;
}
