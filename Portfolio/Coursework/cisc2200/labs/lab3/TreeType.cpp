/********************************************************
 * File : TreeType.cpp
 * Date : 10/10/08
 * Description : Impelementation file of TreeType class
 ********************************************************/

#include "TreeType.h"
#include <new>

TreeType::TreeType()
{
  root = NULL;
   
  preQue = NULL;
  postQue = NULL; 
  inQue = NULL;
}

TreeType::TreeType(const TreeType& originalTree)
{
  CopyTree(root, originalTree.root);
}

void TreeType::operator=(const TreeType& originalTree)
{
  if (&originalTree == this)
  {
    return;
  }

  Destroy(root); 
  CopyTree(root, originalTree.root);
}


void TreeType::CopyTree(TreeNode *&copy, const TreeNode* originalTree)
{
  if (originalTree == NULL)
  {
    copy = NULL;
  }
  else  
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->leftBranch, originalTree->leftBranch);
    CopyTree(copy->rightBranch, originalTree->rightBranch);
  }
}


TreeType::~TreeType()
{
  MakeEmpty();  

  if (preQue !=NULL)  delete preQue;
  if (postQue != NULL) delete postQue;
  if (inQue != NULL) delete inQue;
}

void TreeType::Destroy(TreeNode *& tree)
{
  if (tree!= NULL)
  {
    Destroy(tree->leftBranch);
    Destroy(tree->rightBranch);
    delete tree;
  } 
}

void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}



bool TreeType::IsFull() const
{

  TreeNode * location;
  try{
    location = new TreeNode;
    delete location;
    return false;
  }catch( std::bad_alloc e){
    return true;
  }
}


bool TreeType::IsEmpty() const
{
  return root == NULL;
}

int TreeType::GetLength() const
{
  return Count(root);    
}

int TreeType::Count(TreeNode * tree) const
{
  if (tree == NULL)
  {
    return 0;
  }
  else
  {
    return Count(tree->leftBranch) + Count(tree->rightBranch) +1;
  }
}



void TreeType::RetrieveItem(ItemType & item, bool & found) const
{
  Retrieve(root, item, found);
}


void TreeType::Retrieve(TreeNode* tree, ItemType& item, bool& found) const
{
  if (tree == NULL)
  {
    found = false;                     
  }
  else if (item.ComparedTo(tree->info) == LESS)
  {      
    Retrieve(tree->leftBranch, item, found);
  }
  else if (item.ComparedTo(tree->info) == GREATER)
  {
    Retrieve(tree->rightBranch, item, found);
  }
  else
  {
    item = tree->info;
    found = true;
  }
}   


void TreeType::InsertItem(ItemType item)
{
   Insert(root, item);
}

void TreeType::Insert(TreeNode* & tree, ItemType item)
{
  if (tree == NULL)
  { // Insertion place found.
    tree = new TreeNode;
    tree->rightBranch = NULL;
    tree->leftBranch = NULL;
    tree->info = item;
  }
  else if (item.ComparedTo(tree->info) == LESS)
  {  
    Insert(tree->leftBranch, item);    
  }
  else 
  {
    Insert(tree->rightBranch, item);   
  }
} 


void TreeType::DeleteItem(ItemType item)
{
  Delete(root, item);
}


// first, find which node should be deleted.
void TreeType::Delete(TreeNode*& tree, ItemType item)
{
  if (item.ComparedTo(tree->info) == LESS)
  { 
    Delete(tree->leftBranch, item);   
  }
  else if (item.ComparedTo(tree->info) == GREATER)
  {
    Delete(tree->rightBranch, item);  
  }
  else
  {
     DeleteNode(tree);  // Node found
  }
} 

void TreeType::DeleteNode(TreeNode*&  tree) 
{
  ItemType data;
  TreeNode* tempPtr;

  tempPtr = tree;

  if (tree->leftBranch == NULL) 
  {
    tree = tree->rightBranch;
    delete tempPtr; 
  } 
  else if (tree->rightBranch == NULL)
  {
    tree = tree->leftBranch;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree->leftBranch, data);
    tree->info = data;
    Delete(tree->leftBranch, data);
  }
} 

void TreeType::GetPredecessor( TreeNode* tree, ItemType& data)
{
  while (tree->rightBranch != NULL)
  {
    tree = tree->rightBranch;
  }
  data = tree->info;
}

void TreeType::Print(ofstream & output) const
{
  PrintTree(root, output);
}

void TreeType::Print() const
{
  std::cout<<"Binary Search Tree: (in-order)"<<endl;
  PrintTree(root, std::cout);  
  std::cout<<endl;
}

void TreeType::PrintTree(TreeNode* tree, ostream& output) const
{
  if (tree != NULL)
  {
    PrintTree(tree->leftBranch, output);   
    output <<tree->info<<"  ";
    PrintTree(tree->rightBranch, output);  
  }
}



void TreeType::PreOrder(TreeNode * tree, queue<ItemType>* & preQue)
{
  if (tree != NULL)
  {
    preQue->push(tree->info);
    PreOrder(tree->leftBranch, preQue);
    PreOrder(tree->rightBranch, preQue);
  } 
}



void TreeType::InOrder(TreeNode * tree, queue<ItemType>*& inQue)
{
  if (tree != NULL)
  {
    InOrder(tree->leftBranch, inQue);
    inQue->push(tree->info);      
    InOrder(tree->rightBranch, inQue);
  } 
}



void TreeType::PostOrder(TreeNode * tree, queue<ItemType>* & postQue)
{
  if (tree != NULL)
  {
    PostOrder(tree->leftBranch, postQue);     
    PostOrder(tree->rightBranch, postQue);
    postQue->push(tree->info);       
  } 
}

void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree 
// elements in the desired order.
//the queue should be deleted after using it.
{
  switch (order)
  {
    case PRE_ORDER : preQue = new queue<ItemType>;
                     PreOrder(root, preQue);
                     break;
    case IN_ORDER  : inQue = new queue<ItemType>;
                     InOrder(root, inQue);
                     break;
    case POST_ORDER: postQue = new queue<ItemType>;
                     PostOrder(root, postQue);
                     break;
  }
} 


void TreeType::GetNextItem(ItemType & item, OrderType order, bool& finished)
{
  finished = false;
  switch(order)
  {
    case PRE_ORDER  : item = preQue->front();
                      preQue->pop( );
                      if (preQue->empty())
                      {
                        finished = true;
                        delete preQue;
                        preQue = NULL;
                      }
                      break;
    case IN_ORDER   : item = inQue->front();
                      inQue->pop();
                      if (inQue->empty())
                      {
                        finished = true;
                        delete inQue;
                        inQue = NULL;
                      }
                      break;
    case POST_ORDER: item = postQue->front();
                     postQue->pop(); 
                     if (postQue->empty())
                     {
                       finished = true;
                       delete postQue;
                       postQue = NULL;
                     }
                     break;

  }
}

// functions added by Domenico for Lab 3

// function purpose: returns the number of leaf nodes
// precondition: the tree is initialized
// postcondition: the tree isn't changed
int TreeType::LeafCount() const
{
  return CountLeaves(root);
}

// function purpose: counts all the leaf nodes
// a second function is needed because TreeType::root is private
int TreeType::CountLeaves(TreeNode* tree) const
{
  int leafCounter;
  if (((tree->leftBranch) == NULL) && ((tree->rightBranch) == NULL))
  {
    leafCounter = 1;
  } 
  else if (((tree->leftBranch) == NULL) && ((tree->rightBranch) != NULL))
  {
    leafCounter = CountLeaves(tree->rightBranch);
  }
  else if (((tree->leftBranch) != NULL) && ((tree->rightBranch == NULL)))
  {
    leafCounter = CountLeaves (tree->leftBranch);
  }
  else
  {
    leafCounter = CountLeaves(tree->leftBranch) + CountLeaves(tree->rightBranch);
  }
  return leafCounter;
}

// function: search the tree and print the ancestors of a given node where item is saved
// preconditions: the tree has been initialized and item is in the tree
// postcondition: the tree has not been changed, do not print the node itself
void TreeType::PrintAncestors(ItemType item)
{
  Ancestors(root, item);
}

// function: prints all ancestors of a given node
// a second function is needed because TreeType::root is private
void TreeType::Ancestors(TreeNode* tree, ItemType item)
{
  if (item.ComparedTo(tree->info) == LESS)
  {
    std::cout << tree->info << " ";
    Ancestors(tree->leftBranch, item);
  }
  else if (item.ComparedTo(tree->info) == GREATER)
  {
    std::cout << tree->info << " ";
    Ancestors(tree->rightBranch, item);
  }
  else
  {
    std::cout << "\n";
  }
}

void TreeType::NewDeleteItem(ItemType item)
{
    NewDelete(root, item);
}

// function: Delete the node pointed to by treeNode. This function is similar to the one we 
//   discussed in class with one difference, the node has two children is replaced by its immediate 
//   successor instead of its predecessor.
// precondition: The tree has been initialized.  tree may have zero, one or two children.
// postcondition: treeNode is no longer in the binary search tree. If treeNode is a leaf node or has 
//   only one non-NULL child node, treeNode is deleted; otherwise, the info saved in treeNode is 
//   replaced by its logical successor and the successor's node is deleted. 
// first, find which node should be deleted.
void TreeType::NewDelete(TreeNode *& tree, ItemType item)
{
  if (item.ComparedTo(tree->info) == LESS)
    NewDelete(tree->leftBranch, item);   
  else if (item.ComparedTo(tree->info) == GREATER)
    NewDelete(tree->rightBranch, item);  
  else
    NewDeleteNode(tree);  // Node found
}

// function: Delete the node pointed to by treeNode. This function is similar to the one we 
//   discussed in class with one difference, the node has two children is replaced by its immediate 
//   successor instead of its predecessor.
// precondition: The tree has been initialized.  tree may have zero, one or two children.
// postcondition: treeNode is no longer in the binary search tree. If treeNode is a leaf node or has 
//   only one non-NULL child node, treeNode is deleted; otherwise, the info saved in treeNode is 
//   replaced by its logical successor and the successor's node is deleted. 
void TreeType::NewDeleteNode(TreeNode*& tree) 
{
  ItemType data;
  TreeNode* tempPtr;
  tempPtr = tree;
  
  if (((tree->leftBranch) == NULL) && ((tree->rightBranch) == NULL))
  {
    tree = NULL;
  }
  else if (((tree->leftBranch) == NULL) && ((tree->rightBranch) != NULL))
  {
    tree = tree->rightBranch;
    delete tempPtr; 
  } 
  else if (((tree->leftBranch) != NULL) && ((tree->rightBranch) == NULL))
  {
    tree = tree->leftBranch;
    delete tempPtr; 
  }
  else
  {
    GetSuccessor(tree->rightBranch, data);
    tree->info = data;
    Delete(tree->rightBranch, data);
  }
}

// returns successor element (leftBranchmost rightBranch element)
void TreeType::GetSuccessor( TreeNode* tree,ItemType& data)
{
  while (tree->leftBranch != NULL)
  {
    tree = tree->leftBranch;
  }
  data = tree->info;
}

// function: swap the leftBranch and rightBranch children of every node of the node
// precondition: These two trees have been initialized. 
// postcondition: The original tree is unchanged. The newTree is the mirror image of the original tree.
// function needed to access private variables
void TreeType::Swap(TreeType & originalTree)
{
  SwapTrees(root, originalTree.root); 
}

// function: swap the leftBranch and rightBranch children of every node of the node
// precondition: These two trees have been initialized. 
// postcondition: The original tree is unchanged. The newTree is the mirror image of the original tree.

void TreeType::SwapTrees(TreeNode *& swappedTree, TreeNode * originalTree)
{
  if (originalTree == NULL)
  {
    swappedTree = NULL;
  }
  else
  {
    swappedTree = new TreeNode;
    swappedTree->info = originalTree->info;
    SwapTrees(swappedTree->leftBranch, originalTree->rightBranch);
    SwapTrees(swappedTree->rightBranch, originalTree->leftBranch);
  }
}
