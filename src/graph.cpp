#include "graph.h"

//  Implements the Graph class
//
Graph::Graph()
{
  vertices = std::vector<Vertex>();
  vertex_values = std::unordered_map<Vertex, double, VertexHash>();
  adjacency_list = std::vector<std::vector<Vertex>>();
  edge_values = std::unordered_map<Edge, double, EdgeHash>();
  vertex_symbols_table = std::unordered_map<Vertex, int, VertexHash>();
}

int Graph::GetNumberOfVertices() const {
  return vertices.size();
}

//  Add Vertex to the Graph with default value of inf as defined by the
//  Constants struct.  Inf is chosen as if the value represents distance or
//  cost, then inf is a sensible default value as the goal of most algorithm
//  is minization of cost.
void Graph::AddVertex(const Vertex vertex, double value) {
  // Add vertex to `vertices` the private member variable
  // and add corresponding entry to the adjacency_list
  vertices.push_back(vertex);
  vertex_values[vertex] = value;

  // Construct a blank vector of vertices for the adjacent vertex for v
  std::vector<Vertex> adjacent_vertices{};

  // Push the blank adjacent list to the adjacency list
  adjacency_list.push_back(adjacent_vertices);

  //  Add the vertex to the symbols table mapping the vertex identifier to the
  //  int [index] for use in accessing information contained in vector variables
  int index = vertices.size() - 1;
  vertex_symbols_table[vertex] = index;
}

void Graph::SetVertexValue(const Vertex& vertex, double value) {

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
