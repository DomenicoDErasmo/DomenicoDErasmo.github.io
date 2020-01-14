// Domenico D'Erasmo
// 7 September 2017
// The erroneous code for greetings.cpp

#include <iostream>
using namespoce std; //"namespace" is spelled incorrectly; replace the "o" with an "a".

int main( //The other parenthesis is missing!
{
	cout << "Greetings Earth!" << endl;
	cout << "Time for school!" << endl;
	cout << "How much longer?" << endl;
	return 0 //The semicolon at the end of "return 0;" is missing.
}
