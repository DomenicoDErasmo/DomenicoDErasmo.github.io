// Domenico D'Erasmo
// 6 November 2017
// Prime checker for first extra credit assignment

#include <iostream>
#include <math.h>

void primeCheck(int numberOfPrimes){
	int numberOfPrimesCounter = 0, primeCandidateFactor, primeCandidateFactorCheck = 0, primeCandidate = 3;
	do {
		for (primeCandidateFactor = 2; primeCandidateFactor < (sqrt(primeCandidate) + 1); primeCandidateFactor++) {
			if (primeCandidate % primeCandidateFactor == 0) {
				primeCandidateFactorCheck++;
			}
		}
		if (primeCandidateFactorCheck == 0) {
			numberOfPrimesCounter++;
			primeCandidateFactorCheck = 0;
			std::cout << primeCandidate << " ";
			primeCandidate++;
		} else {
			primeCandidate++;
			primeCandidateFactorCheck = 0;
		}
	} while (numberOfPrimesCounter < (numberOfPrimes - 1));
}
