#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "constants.h"
#include "vertex.h"
#include "edge.h"

class Graph
{
public:
  Graph();
  //  Method : returns the number of vertices in the graph
  int get_number_of_vertices() const ;

  void AddVertex(const Vertex& v, double value = Constants::inf);
  void DeleteVertex(const Vertex& vertex);
  double GetVertexValue(const Vertex& vertex) const;
  void SetVertexValue(const Vertex& vertex, double value);

  void AddEdge(const Edge& edge);
  void DeleteEdge(const Edge& edge);
  double GetEdgeValue(const Edge& edge) const;
  double GetEdgeValue(const Vertex& from, const Vertex& to) const;
  void SetEdgeValue(const Edge& edge);

  //  Methoid : returns the vertices connected to a vertex
  std::vector<Vertex> GetNeighbors(const Vertex& vertex) const;

  std::pair<std::vector<Vertex>, double> GetShortestPath();
  std::pair<std::vector<Edge>, std::vector<double> > GetMinimumSpanningTree();

  std::vector<Vertex>::const_iterator vertex_begin() const;
  std::vector<Vertex>::const_iterator vertex_end() const;
  std::vector<Edge>::const_iterator edge_begin() const;
  std::vector<Edge>::const_iterator edge_end() const;

private:
  //  Vectors of all vertices indexed by an int that can be found using the vertex_symbols_table
  std::vector<Vertex> vertices;
};

#endif // GRAPH_H
