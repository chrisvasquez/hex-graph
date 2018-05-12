#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"
#include "constants.h"

//
//  Class Edge:
//
class Edge
{
public:
  Edge();
  Edge(const Vertex& from,
       const Vertex& to,
       std::string identifier = "",
       double value = Constants::inf)
    : from(from), to(to), identifier(identifier), value(value) {}

  bool operator ==(const Edge& edge) const;
  bool operator <(const Edge& edge) const;

  //  Overloaded << operator
  friend std::ostream& operator<<(std::ostream& out, const Edge& edge);

private:
  Vertex from, to;
  std::string identifier;
  double value;
};

// Custom class for use as the custom hash function for the Edge class
// for use in unordered_map and unordered_set
class EdgeHash {
public:
    std::size_t operator()(const Edge& edge) const;
};
#endif // EDGE_H
