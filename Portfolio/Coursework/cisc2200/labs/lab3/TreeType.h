/***********************************************
 * File : TreeType.h
 * Date : 10/10/08
 * Description : Header file of Class TreeType 
 *               A binary search tree
 **********************************************/
#ifndef TREETYPE_H
#define TREETYPE_H

#include <iostream>
#include <fstream>

#include <queue>

#include "ItemType.h"


class TreeNode{

public:
   ItemType info;
   TreeNode * leftBranch;
   TreeNode * rightBranch;   
}; 

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
public:
  TreeType();
  ~TreeType();
 
  TreeType(const TreeType & originalTree); //copy constructor
  void operator=(const TreeType & originalTree);

  void MakeEmpty();

  bool IsEmpty() const;
  bool IsFull() const;

  int GetLength() const;  //how many nodes in the tree

  void RetrieveItem( ItemType & item, bool & found) const;
  void InsertItem (ItemType item);
  void DeleteItem (ItemType item);

  void ResetTree(OrderType order);
  void GetNextItem(ItemType & item, OrderType order, bool & finished);

  void Print(ofstream & output) const;
  void Print() const;

  // functions added by Domenico for Lab 3
  int LeafCount() const;
  void PrintAncestors(ItemType item);
  void NewDeleteItem(ItemType item);
  void Swap(TreeType & originalTree);

private:

  TreeNode * root;

  queue<ItemType> * preQue;
  queue<ItemType> * inQue;
  queue<ItemType> * postQue;

  void Destroy(TreeNode *& tree);
  void CopyTree(TreeNode *& copy, const TreeNode * originalTree);

  int Count(TreeNode * tree) const;
  void Retrieve(TreeNode * tree, ItemType & item, bool &found) const;
  void Insert(TreeNode *& tree, ItemType item);
  
  void Delete(TreeNode *& tree, ItemType item);
  void DeleteNode(TreeNode *& tree);
  void GetPredecessor (TreeNode * tree, ItemType & item);
  void PrintTree(TreeNode * tree, ostream& output) const;

  void PreOrder(TreeNode* tree, queue<ItemType> *& preQue);
  void InOrder(TreeNode* tree, queue<ItemType> *& inQue);
  void PostOrder(TreeNode* tree, queue<ItemType> *& postQue);

  // added by Domenico for Lab #3

  int CountLeaves(TreeNode* tree) const;
  void Ancestors(TreeNode* tree, ItemType item);
  void NewDelete(TreeNode *& tree, ItemType item);
  void NewDeleteNode(TreeNode*& treeNode);
  void GetSuccessor(TreeNode * tree, ItemType & item);
  void SwapTrees(TreeNode *& swappedTree, TreeNode * originalTree);
};

#endif
