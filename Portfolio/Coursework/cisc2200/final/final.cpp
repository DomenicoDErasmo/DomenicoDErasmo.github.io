// Domenico D'Erasmo
// 10 December 2018
// CS Final Project
// Driver file for the calculator

#include <iostream>
#include "Calculator.h"
#include "ErrorChecker.h"

// Function prototypes
void PrintInfixString(ErrorChecker testCalc);
void PrintPostfixString(ErrorChecker testCalc);
void PrintResult(ErrorChecker testCalc);

int main()
{
  ErrorChecker testCalc;

  do
  {
    testCalc.GetInput();
  } 
  while (testCalc.CheckSyntaxErrors());

  PrintInfixString(testCalc);
  testCalc.InfixToPostfix();
  PrintPostfixString(testCalc); 
  PrintResult(testCalc);
  return 0;
}

void PrintInfixString(ErrorChecker testCalc)
{
  std::cout << "testCalc's infixInput string is ";
  testCalc.PrintInfix(); 
  std::cout << ".\n";
}

void PrintPostfixString(ErrorChecker testCalc)
{
  std::cout << "testCalc's postfixInput string is ";
  testCalc.PrintPostfix(); 
  std::cout << ".\n";
}

void PrintResult(ErrorChecker testCalc)
{
  bool semanticErrorFlag = false;
  double result = testCalc.EvaluatePostfix(semanticErrorFlag);
  
  if (semanticErrorFlag)
  {
    std::cout << "Error: Dividing by zero!\n";
  }
  else
  {
    testCalc.PrintInfix();
    std::cout << " = " << result << ".\n";
  }
}
