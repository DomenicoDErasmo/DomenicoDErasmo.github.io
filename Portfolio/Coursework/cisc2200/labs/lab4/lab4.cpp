// Domenico D'Erasmo
// 19 Novmeber 2018
// Lab #4
// Test file for DirectedWeightedGraph.cpp

#include <iostream>
#include "DirectedWeightedGraph.h"

// The functions prototyped in lab4.cpp could be combined into one "TestGraph" class for
// 	readability, but I didn't give myself a lot of time to implement this!

// function prototypes
void PromptEdgeWeight(int& edgeWeight);
void PromptVertex(VertexType& inputVertex);
void TestAddEdge(DirectedWeightedGraph& testGraph);
void TestAddVertex(DirectedWeightedGraph& testGraph);
void TestDeleteEdge(DirectedWeightedGraph& testGraph);
void TestDeleteVertex(DirectedWeightedGraph& testGraph);
void TestEdgeExists(DirectedWeightedGraph& testGraph);
void TestGetWeight(DirectedWeightedGraph& testGraph);
void TestVertexExists(DirectedWeightedGraph& testGraph);

int main()
{
  // variables
  DirectedWeightedGraph testGraph;
  VertexType inputVertex;

  // testing several implemented functions
  TestAddVertex(testGraph);
  TestAddEdge(testGraph);
  std::cout << "Now printing the graph with breadth-first traversal:\n";
  PromptVertex(inputVertex);
  testGraph.Print(inputVertex);
  TestDeleteVertex(testGraph);
  TestDeleteEdge(testGraph);
  TestGetWeight(testGraph);
  TestEdgeExists(testGraph);
  TestVertexExists(testGraph);
  testGraph.ResetGraphMarks();
 
  return 0;
}

// function implementations

// initializes testGraph
// testGraph must be initialized
void TestAddVertex(DirectedWeightedGraph& testGraph)
{
  int testGraphInput;
  std::cout << "Now initializing the graph:\n";
  std::cout << "Enter integers to add to the graph, enter -1 to stop adding\n";
  while (testGraphInput != -1)
  {
    std::cin >> testGraphInput;
    if (testGraphInput != -1)
    {
      VertexType addedVertex(testGraphInput);
      testGraph.AddVertex(addedVertex);
    }
  }
}

// functions refactored from TestAddEdge to make simpler code

// asks for the vertex value
void PromptVertex(VertexType& inputVertex)
{
  int vertexInput;
  std::cout << "Enter the value of the desired vertex: ";
  std::cin >> vertexInput;
  inputVertex = vertexInput;
}

// asks for the edge weight
void PromptEdgeWeight(int& edgeWeight)
{
  std::cout << "Enter the weight of the edge: ";
  std::cin >> edgeWeight;
}

// tests the AddEdge function
// testGraph must be initialized
void TestAddEdge(DirectedWeightedGraph& testGraph)
{
  VertexType startVertex, endVertex;
  int edgeWeight;
  char redoCheck;

  std::cout << "Entering edge values\n";
  while (redoCheck != 'n')
  { 
    std::cout << "Starting vertex:\n";
    PromptVertex(startVertex);

    std::cout << "Ending vertex:\n";
    PromptVertex(endVertex);
    PromptEdgeWeight(edgeWeight);
    
    testGraph.AddEdge(startVertex, endVertex, edgeWeight);
    std::cout << "Would you like to enter more values (y/n): ";
    std::cin >> redoCheck;
  }
}

void TestDeleteVertex(DirectedWeightedGraph& testGraph)
{
  VertexType deletedVertex;

  std::cout << "Now deleting a vertex\n";
  PromptVertex(deletedVertex);
  testGraph.DeleteVertex(deletedVertex);
}

void TestDeleteEdge(DirectedWeightedGraph& testGraph)
{
  VertexType startVertex, endVertex;

  std::cout << "Now deleting an edge\n";
  std::cout << "Starting vertex:\n";
  PromptVertex(startVertex);
  std::cout << "Ending vertex:\n";
  PromptVertex(endVertex);
  testGraph.DeleteEdge(startVertex, endVertex);
}

void TestGetWeight(DirectedWeightedGraph& testGraph)
{
  VertexType startVertex, endVertex;
  int edgeWeight;

  std::cout << "Now getting edge weight:\n";
  std::cout << "Starting vertex:\n";
  PromptVertex(startVertex);
  std::cout << "Ending vertex:\n";
  PromptVertex(endVertex);
  edgeWeight = testGraph.GetWeight(startVertex, endVertex);
  if (edgeWeight != -1)
  {
    std::cout << "The edge weight is " << edgeWeight << ".\n";
  }
  else
  {
    std::cout << "The edge does not exist in the graph.\n";
  }
}

void TestEdgeExists(DirectedWeightedGraph& testGraph)
{
  VertexType startVertex, endVertex;

  std::cout << "Now testing if an edge exists:\n";
  std::cout << "Starting vertex:\n";
  PromptVertex(startVertex);
  std::cout << "Ending vertex:\n";
  PromptVertex(endVertex);
  if (testGraph.EdgeExists(startVertex, endVertex))
  {
    std::cout << "An edge exists between the two vertices.\n";
  }
  else
  {
    std::cout << "There is no edge between the two vertices.\n";
  }
}

void TestVertexExists(DirectedWeightedGraph& testGraph)
{
  VertexType vertexCandidate;

  std::cout << "Now testing if a vertex exists:\n";
  PromptVertex(vertexCandidate);
  if (testGraph.VertexExists(vertexCandidate))
  {
    std::cout << "The vertex is in the graph.\n";
  }
  else
  {
    std::cout << "The vertex isn't in the graph.\n";
  }
}
