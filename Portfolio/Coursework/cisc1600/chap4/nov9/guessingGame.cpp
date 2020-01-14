// Domenico D'Erasmo
// 9 November 2017
// Lab #8
// Rolls die and flips coin, prompting user to guess both

#include <iostream>
#include <cstdlib>
#include <ctime>

std::string userInput();
int rollAndFlip();
bool results(std::string input, int dieRoll);
bool redoProgram();

int main() {
	std::string input, input2;
	int dieRoll, score = 0;
	do {
		input = userInput();
		dieRoll = rollAndFlip();
		if (results(input, dieRoll)) {
			score = score + 10;
			std::cout << "Your score is " << score << ".\n";
		} else {
			score--;
			std::cout << "Your score is " << score << ".\n";
		}
	} while (redoProgram());
}
