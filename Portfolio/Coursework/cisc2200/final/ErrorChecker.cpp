// Domenico D'Erasmo
// 12 November 2018
// Implementation file for Error.h

#include <iostream>
#include <stack>
#include "ErrorChecker.h"

// Checks for syntax errors in the input
bool ErrorChecker::CheckSyntaxErrors()
{
  if (
    UnbalancedParentheses() ||
    ConsecutiveOperators() ||
    InvalidCharacters()
  )
  {
    std::cout << "Syntax error present! Please enter input again:\n";
    return true;
  }
  else
  {
    return false;
  }
}

// Checks if invalid characters were entered into the expression
bool ErrorChecker::InvalidCharacters()
{
  for (int infixInputPos = 0; infixInputPos < infixInput.length(); infixInputPos++)
  {
    if (CharIsInvalid(infixInput[infixInputPos]))
    {
      std::cout << "Error: Invalid character entered.\n";
      return true;
    }
  }
  return false;
}

// Lists which characters are valid or not
bool ErrorChecker::CharIsInvalid(char examiningChar)
{
  if 
  (
    ((examiningChar >= '(') && (examiningChar <= '+')) ||
    ((examiningChar >= '0') && (examiningChar <= '9')) ||
     (examiningChar == '-')
  )
  {
    return false;
  }
  else
  {
    return true;
  }
}

// Checks for an improper number of parentheses
bool ErrorChecker::UnbalancedParentheses()
{
  std::stack<char> parenthesesCheck;
  for (int infixInputPos = 0; infixInputPos < infixInput.length(); infixInputPos++)
  {
    if (infixInput[infixInputPos] == '(')
    {
      parenthesesCheck.push(infixInput[infixInputPos]);
    }
    else if (infixInput[infixInputPos] == ')')
    {
      if (parenthesesCheck.empty())
      {
        std::cout << "Error: too many )'s!\n";
        return true;
      }
      else
      {
        parenthesesCheck.pop();
      }
    }
  }

  if (parenthesesCheck.empty())
  {
    return false;
  }
  else
  {
    std::cout << "Error: too many ('s!\n";
    return true;
  }
}

// Checks for consecutive operators
bool ErrorChecker::ConsecutiveOperators()
{
  for (int infixInputPos = 0; infixInputPos < (infixInput.length() - 1); infixInputPos++)
  {
    if (CharIsOperator(infixInput[infixInputPos]) && CharIsOperator(infixInput[infixInputPos+1]))
    {
      std::cout << "Error: Consecutive operators!\n";
      return true;
    }
  }
  return false;
}
