// Domenico D'Erasmo
// 9 November 2017
// Lab #8
// Functions for Guessing Game

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string userInput() {
	std::string input;
	std::cout << "Guess a 6-sided dice roll and a coin flip : ";
	getline(std::cin, input);
	return input;
}

int rollAndFlip() {
	int dieRoll;
	srand(time(NULL));
	dieRoll = rand()%12;
	return dieRoll;
}

bool results(std::string input, int dieRoll) {
	char inputRoll = input.at(0), inputFlip = input.at(2), randomRoll, randomFlip;
	switch (dieRoll) {
		case 0:
		case 1:
			randomRoll = '1';
			break;
		case 2:
		case 3:
			randomRoll = '2';
			break;
		case 4:
		case 5:
			randomRoll = '3';
			break;
		case 6:
		case 7:
			randomRoll; '4';
			break;
		case 8:
		case 9:
			randomRoll = '5';
			break;
		case 10:
		case 11:
			randomRoll = '6';
			break;
		default:
			break;
	}
	if ((dieRoll % 2) == 0) {
		randomFlip = 'H';
	} else {
		randomFlip = 'T';
	}
	if ((inputRoll == randomRoll) && (inputFlip == randomFlip)) {
		std::cout << "The roll was " << randomRoll << " and the coin flip was " << randomFlip << ". You guessed correctly!\n";
		return true;
	} else {
		std::cout << "The roll was " << randomRoll << " and the coin flip was " << randomFlip << ". You guessed incorrectly!\n";
		return false;
	}
}

bool redoProgram() {
	std::string redoCheck;
	std::cout << "Would you like to play again? (Yes/No) : ";
	getline(std::cin, redoCheck);
	if ((redoCheck == "Yes") || (redoCheck == "yes")) {
		return true;
	} else {
		std::cout << "Have a nice day!\n";
		return false;
	}
}
