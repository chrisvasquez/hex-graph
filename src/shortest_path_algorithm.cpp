#include "shortest_path_algorithm.h"
#include "vertex_priority_comparator.h"
#include "priority_queue.h"

ShortestPathAlgorithm::ShortestPathAlgorithm()
{

}

std::pair<std::vector<Vertex>, double> ShortestPathAlgorithm::GetShortestPathAndCost(Graph* graph,
                                                                                     const Vertex& from,
                                                                                     const Vertex& to)
{
  return CalculateShortestPathAndCost(graph, from, to);
}

std::pair<std::vector<Vertex>, double> ShortestPathAlgorithm::CalculateShortestPathAndCost(Graph* graph,
                                                                                           const Vertex& from,
                                                                                           const Vertex& to)
{
  // Construct a blank vector of parametrized vertex
  shortest_path = std::vector<Vertex>();
  // Set the shortest_path_cost to the zero value of EdgeCost
  shortest_path_cost = 0.0;

  // Create set all of vertices in set whose connected vertices has not been visited yet
  // The vertices are ordered in increasing value of minimum possible distance from a origin vertex designated as from.
  // PriorityQueue2<int, std::vector<int>, decltype(cmp) > vertex_set = PriorityQueue2(graph->number_of_vertices());
  // PriorityQueue2<int, std::vector<int>, decltype(cmp)> vertex_set(cmp, graph->number_of_vertices());
  VertexPriorityComparator vertex_comparator(graph);
  PriorityQueue<Vertex, std::vector<Vertex>, VertexPriorityComparator> vertex_set(vertex_comparator);

  // Initialize all vertices as members of the vertex_set with default value of inf except for the origin
  // or source with value of 0.0
  for (auto queue_element_it = graph->vertex_begin(); queue_element_it != graph->vertex_end(); ++queue_element_it) {
      vertex_set.insert(*queue_element_it);
      vertex_set.ChangePriority(*queue_element_it, Constants::inf);
    }

  // initialize the from vertex to the zero value of the EdgeCost
  vertex_set.ChangePriority(from, 0.0);
  graph->SetVertexValue(from, 0);

  // Declare the current vertex
  Vertex current_vertex;

  // While the vertex set is not exhausted
  while (vertex_set.size() != 0) {

      // Get vertex `current_vertex` with min value or distance / cost and remove it from the queue
      current_vertex = vertex_set.top();
      vertex_set.pop();

      // Get neighbors of  `current_vertex`
      std::vector<Vertex> neighbors = graph->GetNeighbors(current_vertex);

      // Iterate through the neighbors
      for (auto neighbor : neighbors) {
          //  calculate alternative_value = possible updated cost / value as value(current_vertex) + value of
          //  edge(current_vertex, neighbor)
          //  continue if vertex is already visited and closed already
          if (!vertex_set.contains(neighbor)) continue;
          //  Compure the alternative value of the `neighbor` vertex if the path taken is through the current_vertex
          //  and the edge from current_vertex to neighbor
          double alternative_value = graph->GetVertexValue(current_vertex) + graph->GetEdgeValue(current_vertex, neighbor);
          //  If alternative_value < current value of neighbor, update value of neighbor
          if (alternative_value < graph->GetVertexValue(neighbor)) {
              //  Change vertex priority in PriorityQueue which calls a handler that also changes
              //  the value fo the vertex in the graph and resort the PriorityQueue
              vertex_set.ChangePriority(neighbor, alternative_value);
              graph->SetVertexValue(neighbor, alternative_value);
              //  Set previous_vertex of `neighbor` to `current_vertex`
              //  To set the current_vertex as the path before neighbor that results to the lower
              //  cost of going to neighbor by far
              prev[neighbor.get_identifier()] = current_vertex.get_identifier();
            }
        }
    }

  // Get the final cost of the destination vertex
  shortest_path_cost = graph->GetVertexValue(to);

  // Check if there is no found path, as designated by the shortest path cost being inf
  // and construct the shortest path if a path is found by walking back from the destination vertex
  // to the source vertex using the prev variable
  if (shortest_path_cost != Constants::inf) {
      Vertex walkback_vertex(to.get_identifier(), shortest_path_cost);
      while (walkback_vertex.get_identifier() != from.get_identifier()) {
          walkback_vertex.set_value(graph->GetVertexValue(walkback_vertex));
          shortest_path.push_back(walkback_vertex);
          walkback_vertex = Vertex(prev[walkback_vertex].get_identifier(), 0);
        }
      // Add the origin
      Vertex from_with_zero_value = Vertex(from.get_identifier(), 0.0);
      shortest_path.push_back(from_with_zero_value);
    }
  return std::pair<std::vector<Vertex>, double>(shortest_path, shortest_path_cost);
}
