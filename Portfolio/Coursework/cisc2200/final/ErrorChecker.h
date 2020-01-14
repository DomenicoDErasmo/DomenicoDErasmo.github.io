// Domenico D'Erasmo
// 12 December 2018
// ErrorChecker Class Interface

#ifndef ERRORCHECKER_H
#define ERRORCHECKER_H

#include <iostream>
#include <stack>
#include "Calculator.h"

class ErrorChecker: public Calculator
{
public:
  bool CheckSyntaxErrors();

private:
  bool CharIsInvalid(char examiningChar);
  bool ConsecutiveOperators();
  bool InvalidCharacters();
  bool UnbalancedParentheses();

};

#endif
