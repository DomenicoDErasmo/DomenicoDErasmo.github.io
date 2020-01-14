// Domenico D'Erasmo
// 29 November 2018
// Final Project
// Interface file for Calculator class

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stack>

class Calculator
{

public:
  
  double EvaluatePostfix(bool& semanticErrorFlag);
  void GetInput ();
  void InfixToPostfix();
  void PrintInfix();
  void PrintPostfix();
  
protected:
 
  // functions used in public functions
  bool CharIsAddition(char queryChar);
  bool CharIsDivision(char queryChar);
  bool CharIsMultiplication(char queryChar);
  bool CharIsNumber(char postfixChar);
  bool CharIsOperator(char infixChar);
  bool CharIsSubtraction(char queryChar);
  bool IsHigherPriority(char queryOperator);
  double OperateOnStack(char operatingChar);
  double ParseNumber(int postfixInputPos);
  int GetOperatorPriority(char queryOperator);
  void AddOperatorToStack(char examiningChar);
  void AdjustIndex(int& index);
  void CheckOperatorPriority(char queryOperator, bool& doneFlag);
  void GetDigits(int& infixInputPos);
  void PopAllOperators();
  void PopOperatorsUntilParenthesis();

  // variables
  std::stack<char> operatorStack;
  std::stack<double> numberStack;
  std::string infixInput;
  std::string postfixInput;
    
};

#endif

