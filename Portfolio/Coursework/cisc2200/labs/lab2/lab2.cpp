// Domenico D'Erasmo
// 8 October 2018
// Lab #2
// Program to check if input string is a palindrome

#include <iostream>
#include <stack>

// prototypes
void InputInto (std::string& uncleanedInput);
bool IsValidCharacter (char& characterCandidate);
void CleanInput (std::string& uncleanedInput, std::string& cleanedInput);
void SetPalindromeCandidate (std::string& cleanedInput, std::stack<char>& palindromeCandidate);
bool IsPalindrome (std::string& cleanedInput, std::stack<char>& palindromeCandidate);
void OutputResult (bool& outputFlag, std::string& uncleanedInput);

int main()
{
  // variables
  std::string uncleanedInput, cleanedInput;
  std::stack<char> palindromeCandidate;
  bool palindromeFlag;
	
  // processing
  InputInto(uncleanedInput);
  CleanInput(uncleanedInput, cleanedInput);
  SetPalindromeCandidate (cleanedInput, palindromeCandidate);
  palindromeFlag = IsPalindrome(cleanedInput, palindromeCandidate);
  OutputResult(palindromeFlag, uncleanedInput);
  return 0;
}

// function implementations

// precondition: uncleanedInput is initialized
// postcondition: uncleanedInput is modified
void InputInto (std::string& uncleanedInput)
{
  std::cout << "Enter the palindrome to check: ";
  getline(std::cin, uncleanedInput);
}

// postcondition: returns true if the character is a letter, returns false if not
bool IsValidCharacter(char& characterCandidate)
{
  if (((characterCandidate >= 'A') && (characterCandidate <= 'Z')) || ((characterCandidate >= 'a') && (characterCandidate <= 'z')))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// precondition: uncleanedInput is initialized, palindromeCandidate is initialized
// postcondition: palindromeCandidate becomes uncleanedInput with only letters
void CleanInput (std::string& uncleanedInput, std::string& cleanedInput)
{
  int cleanedStringPosition = 0;
  for (int uncleanedStringPosition = 0; uncleanedStringPosition < uncleanedInput.length(); uncleanedStringPosition++)
  {
    if (IsValidCharacter(uncleanedInput[uncleanedStringPosition]))
    {
      cleanedInput.resize(cleanedStringPosition + 1);
      if ((uncleanedInput[uncleanedStringPosition] >= 'A') && (uncleanedInput[uncleanedStringPosition] <= 'Z'))
      {
        cleanedInput[cleanedStringPosition] = uncleanedInput[uncleanedStringPosition] + 32;
      }
      else
      {
        cleanedInput[cleanedStringPosition] = uncleanedInput[uncleanedStringPosition];
      }
      cleanedStringPosition++;
    }
  }
}

// precondition: cleanedInput is initialized, palindromeCandidate is initialized
// postcondition: palindromeCandidate is set to cleanedInput
void SetPalindromeCandidate (std::string& cleanedInput, std::stack<char>& palindromeCandidate)
{
  for (int stringPosition = 0; stringPosition < cleanedInput.length(); stringPosition++)
  {
    palindromeCandidate.push(cleanedInput[stringPosition]);
  }
}

// precondition: cleanedInput is initialized, palindromeCandidate is initialzied
// postcondition: returns true if palindromeCandidate is a palindrome, false if not
bool IsPalindrome (std::string& cleanedInput, std::stack<char>& palindromeCandidate)
{
  char comparingCharacter;
  for (int stringPosition = 0; stringPosition <= cleanedInput.length()/2; stringPosition++)
  {
    comparingCharacter = palindromeCandidate.top();
    if ((comparingCharacter != cleanedInput[stringPosition]))
    {
      return false;
    }
    else
    {
      palindromeCandidate.pop();
    }
  }
  return true;
}

void OutputResult (bool& outputFlag, std::string& uncleanedInput)
{
  if (outputFlag == true)
  {
    std::cout << "\"" << uncleanedInput << "\"" << " is a palindrome.\n";
  }
  else
  {
    std::cout << "\""<< uncleanedInput << "\"" << " is not a palindrome.\n";
  }
}
