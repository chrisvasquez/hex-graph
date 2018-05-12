#include "graph.h"

//  Implements the Graph class
//
Graph::Graph()
{
  vertices = std::vector<Vertex>();
}

void Graph::SetVertexValue(const Vertex& vertex, double value = 0) {

}

double Graph::GetVertexValue(const Vertex& vertex) const {
  return 0;
}

double Graph::GetEdgeValue(const Edge& edge) const {
  return 0;
}

double Graph::GetEdgeValue(const Vertex& from, const Vertex& to) const {
  return 0;
}


std::vector<Vertex> Graph::GetNeighbors(const Vertex& vertex) const {
  return std::vector<Vertex>();
}

std::vector<Vertex>::const_iterator Graph::vertex_begin() const {
  return vertices.begin();
}

std::vector<Vertex>::const_iterator Graph::vertex_end() const {
  return vertices.end();
}

//  std::vector<Edge>::const_iterator Graph::edge_begin() const;
//  std::vector<Edge>::const_iterator Graph::edge_end() const;
