// Domenico D'Erasmo
// 4 November 2018
// Lab #3
// Program to test new functions

// libraries to include
#include <iostream>
#include "TreeType.h"
#include "ItemType.h"

// function prototypes
void InitializeTree(TreeType& testingTree);
void TestLeafCount(const TreeType& testingTree);
void TestAncestors(TreeType& testingTree);
void TestDeleteNode(TreeType& testingTree);
void TestSwap(TreeType& swapTree, TreeType& testingTree);

int main()
{
  // variables
  TreeType testingTree, swapTree;
  
  // function tests
  InitializeTree(testingTree);
  TestLeafCount(testingTree);
  TestAncestors(testingTree);
  TestDeleteNode(testingTree);
  TestSwap(swapTree, testingTree);
  return 0;
}

// function definitions
void InitializeTree(TreeType& testingTree)
{
  char treeCandidate;
  ItemType addChar;
  std::cout << "Enter characters for the binary list separated by newlines. Enter a * to stop entering characters.\n"; 
  do
  {
    std::cin >> treeCandidate;
    if (treeCandidate != '*')
    {
      addChar.Initialize(treeCandidate);
      testingTree.InsertItem(addChar);
    }
  } while (treeCandidate != '*');
}

void TestLeafCount(const TreeType& testingTree)
{
  std::cout << "The tree has " << testingTree.LeafCount() << " leaf nodes.\n";
}

void TestAncestors(TreeType& testingTree)
{
  char ancestorsQuery;
  ItemType ancestorItem;;
  std::cout << "Enter a character to find its ancestors. Make sure it is in the tree: ";
  std::cin >> ancestorsQuery;
  ancestorItem.Initialize(ancestorsQuery);
  testingTree.PrintAncestors(ancestorItem);
}

void TestDeleteNode(TreeType& testingTree)
{
  char deleteQuery;
  ItemType deleteItem;
  std::cout << "Enter a character to delete. Make sure it is in the tree: ";
  std::cin >> deleteQuery;
  deleteItem.Initialize(deleteQuery);
  testingTree.NewDeleteItem(deleteItem);
  testingTree.Print();
}

void TestSwap(TreeType& swapTree, TreeType& testingTree)
{
  swapTree.Swap(testingTree);
  std::cout << "user-initialized tree: \n";
  testingTree.Print();
  std::cout << "swapped tree: \n";
  swapTree.Print();
}
