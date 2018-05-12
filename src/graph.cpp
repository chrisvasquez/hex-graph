#include "graph.h"

//  Implements the Graph class
//
Graph::Graph(bool is_undirected, bool has_unique_edges)
  : is_undirected(is_undirected), has_unique_edges(has_unique_edges) {
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
void Graph::AddVertex(const Vertex& vertex, double value) {
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

//  Function to add an edge to the graph.  The implementation currently will
//  allow multiple edges between vertices.  In real world example with reoad,
//  two intersections may be connected by more than 1 road, 1 being a toll
//  road and another a non-toll raod. Additionally,
void Graph::AddEdge(const Vertex& from,
                    const Vertex& to,
                    double value) throw(std::logic_error) {
  if (true) { // edge can be added
      //  Add `to` to the neighbors list of `from`
      //  Needs to do a sanity check if from_iterator is end()
      auto from_iterator = vertex_symbols_table.find(from);
      int from_index = from_iterator->second;
      auto adjacent_vertices_of_from = adjacency_list[from_index];
      adjacent_vertices_of_from.push_back(to);
      adjacency_list[from_index] = adjacent_vertices_of_from;

      //  If the graph is undirected :
      //  Store vertex 'from` as an adjacent vertex of vertex `to`
      //  Need to do assertion checking as sanity check
      //  Current code assumes the `from` vertex is in the adjacency_list of `to` if
      //  `to` is in the adjacency_list of `from`
      if (is_undirected) {
          //  Get iterator for the `to` vertex
          auto to_iterator = vertex_symbols_table.find(to);
          int to_index = to_iterator->second;
          auto adjacent_vertices_of_to = adjacency_list[to_index];
          adjacent_vertices_of_to.push_back(from);
          adjacency_list[to_index]= adjacent_vertices_of_to;
        }
      // Store the value / cost of the edge
      Edge key{from, to};
      edge_values[key] = value;
    } else {
      throw std::logic_error("Attempt to add a vertex failed.");
    }
  /*
  //  Find the iterator in the symbols table for the `from` vertex
  auto from_iterator = vertex_symbols_table.find(from.get_identifier());
  //  If the from vertex is in the sympbols table
  if (from_it != vertex_symbols_table.end()) {
      //  Get the vertices connected to `from`
      std::vector<vertex<VertexIdentifier, VertexValue>> adjacent_vertices_from = (*adjacency_list)[from_it->second];
      // Check if the vertex `to` is not yet in the neighbors list of `from`, if it is already in the adjacency_list, do nothing
      if (std::find(adjacent_vertices_from.begin(), adjacent_vertices_from.end(), to) == adjacent_vertices_from.end()) {
          //  Add `to` to the neighbors list of `from`
          adjacent_vertices_from.push_back(to);
          (*adjacency_list)[from_it->second] = adjacent_vertices_from;

          //  Store the adjacent vertex on the higher numbered vertex `to`
          //  Get iterator for the `to` vertex
          //  Need to do assertion checking as sanity check
          //  Current code assumes the `from` vertex is in the adjacency_list of `to` if
          //  `to` is in the adjacency_list of `from`
          auto to_it = vertex_symbols_table.find(to.get_identifier());
          auto adjacent_vertices_to = (*adjacency_list)[to_it->second];
          adjacent_vertices_to.push_back(from);
          (*adjacency_list)[to_it->second]= adjacent_vertices_to;

          // Store the value / cost of the edge
          edge<EdgeCost, VertexIdentifier, VertexValue> key = edge<EdgeCost, VertexIdentifier, VertexValue>(from, to);
          edge_values[key] = cost;
        }
    } else {
      assert("Error: The vertex is not found in the graph symptoms table.");
    }
    */
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
