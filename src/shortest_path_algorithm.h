#ifndef SHORTEST_PATH_ALGORITHM_H
#define SHORTEST_PATH_ALGORITHM_H

#include <vector>
#include <unordered_map>
#include "vertex.h"
#include "graph.h"

class ShortestPathAlgorithm
{
public:
    ShortestPathAlgorithm();
    std::pair<std::vector<Vertex>, double> GetShortestPathAndCost(Graph* graph, const Vertex& from, const Vertex& to);
private:
    //  Private member variable to store shortest path and shortest path cost
    std::vector<Vertex> shortest_path;
    double shortest_path_cost;

    //  Private convenience variable to store the vertex prior to the current vertex where the shortest path is
    std::unordered_map<Vertex, Vertex> prev;

    //  Delegate methods
    //  std::function<void(int, double)> priority_change_handler;
    //  std::function<double(int)> priority_checker;

    // Function:
    //     calculate_shortest_path_and_cost: calculates shortest path and cost and stores the calculated values
    //                                       in the private member variables above
    // Parameters
    //     int from, int to
    // Returns:
    //     void : no return variables but stores results in internal member variables
    std::pair<std::vector<Vertex>, double> CalculateShortestPathAndCost(Graph* graph, const Vertex& from, const Vertex& to);
};

#endif // SHORTEST_PATH_ALGORITHM_H
