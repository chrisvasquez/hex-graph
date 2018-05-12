#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>

#include "constants.h"
#include "vertex.h"
#include "edge.h"

class Graph
{
public:
  Graph();
  //  Method : returns the number of vertices in the graph
  int GetNumberOfVertices() const ;

  void AddVertex(const Vertex vertex, double value = Constants::inf);
  // void DeleteVertex(const Vertex& vertex);
  void SetVertexValue(const Vertex& vertex, double value);
  double GetVertexValue(const Vertex& vertex) const;

  void AddEdge(const Edge& edge);
  // void DeleteEdge(const Edge& edge);
  void SetEdgeValue(const Edge& edge);
  double GetEdgeValue(const Edge& edge) const;
  double GetEdgeValue(const Vertex& from, const Vertex& to) const;

  //  Methoid : returns the vertices connected to a vertex
  std::vector<Vertex> GetNeighbors(const Vertex& vertex) const;

  std::pair<std::vector<Vertex>, double> GetShortestPath();
  std::pair<std::vector<Edge>, std::vector<double> > GetMinimumSpanningTree();

  std::vector<Vertex>::const_iterator vertex_begin() const;
  std::vector<Vertex>::const_iterator vertex_end() const;
  std::vector<Edge>::const_iterator edge_begin() const;
  std::vector<Edge>::const_iterator edge_end() const;

private:
  //  Vectors of all vertices indexed by an int that can be found using the
  //  vertex_symbols_table
  std::vector<Vertex> vertices;

  // The value of each vertex; used on shortest path algorithm
  std::unordered_map<Vertex, double, VertexHash> vertex_values;

  // Vectors of vectors of ints that designates the vertices adjacent to each vertex
  std::vector<std::vector<Vertex>> adjacency_list;

  // The value or cost of each edge; used in different graph algorithms
  std::unordered_map<Edge, double, EdgeHash> edge_values;

  //  Symbol table for the vertices
  //  Translates from the vertex identifier to the int index for the vectors
  //  holding information related to the vertex
  std::unordered_map<Vertex, int, VertexHash> vertex_symbols_table;
};

#endif // GRAPH_H
