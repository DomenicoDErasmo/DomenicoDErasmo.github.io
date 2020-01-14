#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H

#include <iostream>
#include <queue>
#include "ItemType.h"

enum  MARK { DEFAULT, VISITED, QUEUED };

struct VertexType{
   
  PItemType item;
  MARK mark;        //default mark = DEFAULT; if visited, mark= VISITED, if queued, mark = QUEUED;
  
  // added by Domenico
  // default constructor
  VertexType()
  {
    mark = DEFAULT;
  }

  // added by Domenico
  // constructor
  VertexType(int itemValue)
  {
    item.Initialize(itemValue, 0);
    mark = DEFAULT;
  }

  // added by Domenico
  VertexType& operator = (VertexType& rightVertex)
  {
    item = rightVertex.item;
    return *this;
  }
  
  // added by Domenico
  VertexType& operator = (int vertexValue)
  {
    item.Initialize(vertexValue, 0);
    return *this;
  }
  
  // added by Domenico
  friend bool operator == (const VertexType& leftVertex, const VertexType& rightVertex)
  {
    return (leftVertex.item.ComparedTo(rightVertex.item) == EQUAL);
  }
  
  // added by Domenico
  friend std::ostream& operator << (std::ostream& output, const VertexType& outputVertex)
  {
    output << outputVertex.item;
    return output;
  }

  bool IsEqual(const VertexType& comparedVertex)
  {
    if (item.ComparedTo(comparedVertex.item) == EQUAL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

class DirectedWeightedGraph{

public:

  // Constructors
  DirectedWeightedGraph();
  DirectedWeightedGraph(int inputMaxVertices);  // specify the max number of vertices

  // Destructor
  ~DirectedWeightedGraph();

  bool IsEmpty() const;
  bool IsFull() const;

  // Add a vertex.
  void AddVertex(VertexType addedVertex);

  // Add an edge from startVertex to endVertex with weight edgeWeight, 
  // startVertex and endVertex must already be in the graph.
  void AddEdge(VertexType startVertex, VertexType endVertex, int edgeWeight);
  
  // Delete a vertex, also delete edges connecting this vertex if they exist.
  // The vertex must be in the graph to be deleted.
  void DeleteVertex(VertexType deletedVertex);

  // Delete all edges involving deletedVertex
  void DeleteAllEdges(VertexType deletedVertex);

  // Delete an edge from startVertex to endVertex. The edge must be in the graph.
  void DeleteEdge(VertexType startVertex, VertexType endVertex);

  // Find the weight of an edge connecting startVertex and endVertex.
  int GetWeight(VertexType startVertex, VertexType endVertex);

  // Find whether there is an edge from startVertex to endVertex.
  bool EdgeExists(VertexType startVertex, VertexType endVertex);

  // Find whether there is a vertex vertexCandidate.
  bool VertexExists(VertexType vertexCandidate);

  // Breadth-first traversal
  void Print(VertexType startVertex);

  // Mark whether the vertex has been visited or queued.
  void MarkVertex(VertexType& markedVertex, MARK newMark);

  // Get the neighbors of the vertex
  void GetNeighbors(VertexType queryVertex, std::queue<VertexType>& neighborQueue);

  // Reset the marks of the graph
  void ResetGraphMarks();

private:

  int numberOfVertices;
  int maxVertices;

  // Save all the vertices        
  VertexType * vertices;

  // Save all the edges
  int edges[50][50];

  // Find the Index of the vertex in the graph
  int IndexIs(VertexType queryVertex);

};


#endif
