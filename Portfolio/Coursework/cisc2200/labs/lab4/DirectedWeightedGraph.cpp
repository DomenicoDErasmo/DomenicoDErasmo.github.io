// Domenico D'Erasmo
// 19 November 2018
// Lab 4
// Implementation of DirectedWeightedGraph

#include "DirectedWeightedGraph.h"

// Default constructor
DirectedWeightedGraph::DirectedWeightedGraph()
{
  numberOfVertices = 0;
  maxVertices = 50;
  vertices = new VertexType[maxVertices];
}

// Constructor for max number of vertices
DirectedWeightedGraph::DirectedWeightedGraph(int inputMaxVertices)
{
  numberOfVertices = inputMaxVertices;
  maxVertices = 50;
  vertices = new VertexType[maxVertices];
 
  // initialize the edges array
  for (int edgeRowIndex = 0; edgeRowIndex < numberOfVertices; edgeRowIndex++)
  {
    for (int edgeColumnIndex = 0; edgeColumnIndex < numberOfVertices; edgeColumnIndex++)
    {
      edges[edgeRowIndex][edgeColumnIndex] = -1;
    }
  } 
}

// Destructor
DirectedWeightedGraph::~DirectedWeightedGraph()
{
  delete[] vertices;
}

// Checks if the graph is empty
bool DirectedWeightedGraph::IsEmpty() const
{
  if (numberOfVertices == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
  
// Checks if the graph is full
bool DirectedWeightedGraph::IsFull() const
{
  if (numberOfVertices == maxVertices)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Add a vertex.
void DirectedWeightedGraph::AddVertex(VertexType addedVertex)
{
  vertices[numberOfVertices] = addedVertex;
  numberOfVertices++;
  for (int initializeNewEdges = 0; initializeNewEdges < numberOfVertices; initializeNewEdges++)
  {
    edges[numberOfVertices][initializeNewEdges] = -1;
    edges[initializeNewEdges][numberOfVertices] = -1;
  }
}

// returns the index of the vertex
// precondition: the vertex is already in the graph
int DirectedWeightedGraph::IndexIs(VertexType queryVertex)
{
  for (int searchIndex = 0; searchIndex < numberOfVertices; searchIndex++)
  {
    if (vertices[searchIndex].IsEqual(queryVertex))
    {
      return searchIndex;
    }
  }
  return -1;
}

// Add an edge from startVertex to endVertex with weight edgeWeight, 
// startVertex and endVertex must already be in the graph 
void DirectedWeightedGraph::AddEdge(VertexType startVertex, VertexType endVertex, int edgeWeight)
{
  edges[IndexIs(startVertex)][IndexIs(endVertex)] = edgeWeight;
}

// Delete a vertex, also delete edges connecting this vertex if they exist.
// The vertex must be in the graph to be deleted.
void DirectedWeightedGraph::DeleteVertex(VertexType deletedVertex)
{
  // plan: set last vertex equal to deletedVertex index, 
  // change addresses of edges array to keep consistent
  DeleteAllEdges(deletedVertex);
  vertices[IndexIs(deletedVertex)] = vertices[numberOfVertices - 1];
  numberOfVertices--;
}

// Deletes an edge from startVertex to endVertex. The edge must be in the graph
void DirectedWeightedGraph::DeleteEdge(VertexType startVertex, VertexType endVertex)
{
  edges[IndexIs(startVertex)][IndexIs(endVertex)] = -1;
}

// Delete all edges involving deletedVertex
void DirectedWeightedGraph::DeleteAllEdges(VertexType deletedVertex)
{
  for (int outerEdgeIndex = 0; outerEdgeIndex < numberOfVertices; outerEdgeIndex++)
  {
    edges[IndexIs(deletedVertex)][outerEdgeIndex] = edges[numberOfVertices - 1][outerEdgeIndex];
    edges[outerEdgeIndex][IndexIs(deletedVertex)] = edges[outerEdgeIndex][numberOfVertices - 1];
  }
}

// Find the weight of an edge connecting startVertex and endVertex.
int DirectedWeightedGraph::GetWeight(VertexType startVertex, VertexType endVertex)
{
  return edges[IndexIs(startVertex)][IndexIs(endVertex)];
}

// Find whether there is an edge from startVertex to endVertex/
bool DirectedWeightedGraph::EdgeExists(VertexType startVertex, VertexType endVertex)
{
  if (edges[IndexIs(startVertex)][IndexIs(endVertex)] != -1)
  {
    return true;
  }
  else
  {
    std::cout << "default case: " << edges[IndexIs(startVertex)][IndexIs(endVertex)] << std::endl;
    return false;
  } 
}

// Find whether there is a vertex vertexCandidate.
bool DirectedWeightedGraph::VertexExists(VertexType vertexCandidate)
{
  for (int verticesIndex = 0; verticesIndex < numberOfVertices; verticesIndex++)
  {
    if (vertices[verticesIndex] == vertexCandidate)
    {
      return true;
    }
  }
  return false;
}

// Get the neighbors of vertex queryVertex
void DirectedWeightedGraph::GetNeighbors(VertexType queryVertex, std::queue<VertexType>& neighborQueue)
{
  for (int neighborIndex = 0; neighborIndex < numberOfVertices; neighborIndex++)
  {
    if ((edges[IndexIs(queryVertex)][neighborIndex] != -1) && (vertices[neighborIndex].mark == DEFAULT))
    {
      neighborQueue.push(vertices[neighborIndex]);
      std::cout << " " << vertices[neighborIndex] << " was added \n"; 
      MarkVertex(vertices[neighborIndex], VISITED);
    }
  }
}

// Prints the graph, using breadth-first traversal
void DirectedWeightedGraph::Print(VertexType startVertex)
{
  std::queue<VertexType> neighborQueue;
  neighborQueue.push(startVertex);
  MarkVertex(vertices[IndexIs(startVertex)], VISITED);
  while(!neighborQueue.empty())
  {
    // gameplan:
    // 1. visit unvisited neighbors, mark as visited, display, insert in queue
    // 2. if no unvisited neighbors found, remove from queue
    // 3. repeat until queue is empty
    MarkVertex(neighborQueue.front(), VISITED);
    std::cout << neighborQueue.front() << " \n";
    GetNeighbors(neighborQueue.front(), neighborQueue);
    neighborQueue.pop();
  }
  std::cout << std::endl;
}

// Mark whether the vertex has been visited or queued
void DirectedWeightedGraph::MarkVertex(VertexType& markedVertex, MARK newMark)
{
  markedVertex.mark = newMark;
}

// Resets the marks of the graph
void DirectedWeightedGraph::ResetGraphMarks()
{
  for(int vertexIndex = 0; vertexIndex < numberOfVertices; vertexIndex++)
  {
    vertices[vertexIndex].mark = DEFAULT;
  }
}
