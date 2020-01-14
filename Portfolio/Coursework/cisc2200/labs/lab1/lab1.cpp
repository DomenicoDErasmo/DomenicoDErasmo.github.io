// Domenico D'Erasmo
// 21 September 2018
// Lab1
// Test file

#include <iostream>
#include "UnsortedType.h"

// function prototypes
void PromptInput(ItemType addToArray[], int capacity);
void PromptSplitKey(ItemType& splitKey, int& keyChanger);
void InitializeUnsortedListByArray (UnsortedListByArray& test, int capacity, ItemType addToArray[]);
void PromptDeleteKey(ItemType& deleteKey, int& keyChanger);
void PromptUniqueInsertKey(ItemType& uniqueInputKey, int& keyChanger);
 
int main()
{
  // variables
  int capacity = 7, keyChanger;
  UnsortedListByArray test, testListOne, testListTwo, mergeTest;
  ItemType addToArray[capacity], listChangingKey;
  bool done;

  // input
  PromptInput(addToArray, capacity);

  // initializing main list
  InitializeUnsortedListByArray(test, capacity, addToArray);

  // prompt for key to split list from
  PromptSplitKey(listChangingKey, keyChanger);

  // testing SplitList
  test.SplitList(listChangingKey, testListOne, testListTwo);
  std::cout << "listOne: \n";
  testListOne.OutputList();
  std::cout << "listTwo: \n";
  testListTwo.OutputList();

  // testing MergeList
  mergeTest.MergeList(testListOne, testListTwo);
  std::cout << "mergeList: \n";
  mergeTest.OutputList();
  
  // prompt for key to insert to list
  PromptUniqueInsertKey (listChangingKey, keyChanger);

  // testing new InsertItem
  test.InsertItem (listChangingKey, done);
  std::cout << "testList: \n";
  test.OutputList();

  // prompt for key to completely delete from list
  PromptDeleteKey (listChangingKey, keyChanger);

  // testing DeleteAllItems
  test.DeleteAllItems (listChangingKey);
  std::cout << "testList:\n";
  test.OutputList();
  return 0;
}

void PromptInput (ItemType addToArray[], int capacity)
{
  for (int loopIndex = 0; loopIndex < capacity; loopIndex++)
  {
    int arrayInitializer;
    std::cout << "Enter value #" << (loopIndex+1) << ": ";
    std::cin >> arrayInitializer;
    addToArray[loopIndex].Initialize(arrayInitializer);  
  }
}

void PromptSplitKey (ItemType& splitKey, int& keyChanger)
{ 
  std::cout << "Enter a value to split the list with: ";
  std::cin >> keyChanger;
  splitKey.Initialize(keyChanger);
}

void InitializeUnsortedListByArray (UnsortedListByArray& test, int capacity, ItemType addToArray[])
{
  for (int loopIndex = 0; loopIndex < capacity; loopIndex++)
  {
    test.InsertItem(addToArray[loopIndex]);
  }
} 

void PromptDeleteKey (ItemType& deleteKey, int& keyChanger)
{
  std::cout << "Enter a value to delete from the list: ";
  std::cin >> keyChanger;
  deleteKey.Initialize(keyChanger);
}

void PromptUniqueInsertKey (ItemType& uniqueInsertKey, int& keyChanger)
{
  std::cout << "Enter a unique value to add to the list: ";
  std::cin >> keyChanger;
  uniqueInsertKey.Initialize(keyChanger);
} 
