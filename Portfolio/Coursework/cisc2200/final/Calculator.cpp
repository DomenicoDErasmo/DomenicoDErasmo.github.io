// Domenico D'Erasmo
// 29 November 2018
// Final Project
// Implementation file for Calculator class

#include <iostream> 
#include <cmath>
#include "Calculator.h" 

// Prompts user for input
void Calculator::GetInput()
{
  std::cout << "Enter a sequence of operations: \n";
  std::cin >> infixInput;
}

// Gets the digits from infix and creates a discernable number in postfix 
// Precondition: infixInput is initialized
void Calculator::GetDigits(int& infixInputPos)
{
  while (CharIsNumber(infixInput[infixInputPos]))
  {
    postfixInput.push_back(infixInput[infixInputPos]);
    infixInputPos++;
  }
  postfixInput.push_back(' ');
}

// Converts infix to postfix
// Precondition: infixInput is initialized
void Calculator::InfixToPostfix()
{
  char examiningChar;
  for (int infixInputPos = 0; infixInputPos < infixInput.length(); infixInputPos++)
  {
    examiningChar = infixInput[infixInputPos];
    if (CharIsNumber(examiningChar))
    {
      GetDigits(infixInputPos);
      
      // accounts for increment of loop
      infixInputPos--;
    }
    else if (examiningChar == '(')
    {
      operatorStack.push(examiningChar);
    }
    else if (CharIsOperator(examiningChar))
    {
      AddOperatorToStack(examiningChar);
    }
    else if (examiningChar == ')')
    {
      PopOperatorsUntilParenthesis();
    }
  }

  PopAllOperators();
}

// Checks if the character is a number
bool Calculator::CharIsNumber(char postfixChar)
{
  if ((postfixChar >= '0') && (postfixChar <= '9'))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Checks if the character is an operator
bool Calculator::CharIsOperator(char infixChar)
{
  if (
    CharIsAddition(infixChar) || 
    CharIsSubtraction(infixChar) || 
    CharIsMultiplication(infixChar) || 
    CharIsDivision(infixChar)
  )
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Adds operators to stack according to the algorithm given by the professor
void Calculator::AddOperatorToStack(char examiningChar)
{
  bool doneFlag = false;
  while (doneFlag == false)
  {
    if (operatorStack.empty())
    {
      operatorStack.push(examiningChar);
      doneFlag = true;
    }
    else if (operatorStack.top() == '(')
    {
      operatorStack.push(examiningChar);
      doneFlag = true;
    }
    else if (CharIsOperator(operatorStack.top()))
    {
      CheckOperatorPriority(examiningChar, doneFlag);
    }
  }
}

// Acts on stack based on operator priority
void Calculator::CheckOperatorPriority(char queryOperator, bool& doneFlag)
{
  if (IsHigherPriority(queryOperator))
  {
    operatorStack.push(queryOperator);
    doneFlag = true;
  }
  else
  {
    postfixInput.push_back(operatorStack.top());
    operatorStack.pop();
  }
}

// Checks for higher priority when compared to the top of the operator stack
bool Calculator::IsHigherPriority(char queryOperator)
{
  if (GetOperatorPriority(queryOperator) > GetOperatorPriority(operatorStack.top()))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Gives operator priority, can be expanded to include other operations
int Calculator::GetOperatorPriority(char queryOperator)
{
  switch (queryOperator)
  {
    case '*':
    case '/':
      return 2;
      break;
    case '+':
    case '-':
      return 1;
      break;
    default:
      return 0;
      break;
  }
}

// Pops all operators until a parenthesis is encountered
void Calculator::PopOperatorsUntilParenthesis()
{
  while(operatorStack.top() != '(')
  {
    postfixInput.push_back(operatorStack.top());
    operatorStack.pop();
  } 
  operatorStack.pop();
}

// Pops all operators from the stack
void Calculator::PopAllOperators()
{
  while(!operatorStack.empty())
  {
    postfixInput.push_back(operatorStack.top());
    operatorStack.pop();
  }
}

// Prints infixInput
void Calculator::PrintInfix()
{
  std::cout << infixInput;
}

// Prints postfixInput
void Calculator::PrintPostfix()
{
  std::cout << postfixInput; 
}

// Converts the number from string to double
double Calculator::ParseNumber(int postfixInputPos)
{
  double result = 0;
  
  while (postfixInput[postfixInputPos] != ' ')
  {
    result = 10*result + (postfixInput[postfixInputPos]-48); // convert ASCII value to int
    postfixInputPos++;
  }
  return result;
}

// Readjustes the string index
void Calculator::AdjustIndex(int& index)
{
  while (postfixInput[index] != ' ')
  {
    index++; 
  }

  // accomodates for increment of loop
  index--;
}

// Evaluates the postfix expression and checks for division by zero
double Calculator::EvaluatePostfix(bool& semanticErrorFlag)
{
  double currentResult;
  char examiningChar;
  
  for (int postfixInputPos = 0; postfixInputPos < postfixInput.length(); postfixInputPos++)
  {
    double currentResult;

    examiningChar = postfixInput[postfixInputPos];
    if (CharIsNumber(examiningChar))
    {
      numberStack.push(ParseNumber(postfixInputPos));
      AdjustIndex(postfixInputPos);
    }
    else if (CharIsOperator(examiningChar))
    {
      currentResult = OperateOnStack(examiningChar);
    }
    if (!std::isfinite(currentResult))
    {
      semanticErrorFlag = true;
      break;
    }
  }
  currentResult = numberStack.top();
  return currentResult;
}

// Performs operation on the top two operands on the stack
double Calculator::OperateOnStack (char operatingChar)
{
  double firstOperand, secondOperand, result = 0;
  
  secondOperand = numberStack.top();
  numberStack.pop();
  firstOperand = numberStack.top();
  
  if (CharIsAddition(operatingChar))
  {
    result = firstOperand + secondOperand;
    numberStack.push(result);
  }
  else if (CharIsDivision(operatingChar))
  {
    result = firstOperand / secondOperand;
    numberStack.push(result);
  }
  else if (CharIsMultiplication(operatingChar))
  {
    result = firstOperand * secondOperand;
    numberStack.push(result);
  }
  else if (CharIsSubtraction(operatingChar))
  {
    result = firstOperand - secondOperand;
    numberStack.push(result);
  }
  return result;
}

// Checks if the character is a +
bool Calculator::CharIsAddition(char queryChar)
{
  if (queryChar == '+')
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Checks if the character is a /
bool Calculator::CharIsDivision(char queryChar)
{
  if (queryChar == '/')
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Checks if the character is a *
bool Calculator::CharIsMultiplication(char queryChar)
{
  if (queryChar == '*')
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Checks if the character is a -
bool Calculator::CharIsSubtraction(char queryChar)
{
  if (queryChar == '-')
  {
    return true;
  }
  else
  {
    return false;
  }
}

