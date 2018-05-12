#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"
#include "constants.h"

//  Forward declaration of the class for use in the definition of the
//  overloaded std::hash and the << operator
class Edge;

//  Declaration of the overloaded std::hash and << operator
namespace std {
  template <>
  struct hash<Edge> {
    size_t operator ()(const Edge& edge) const;
  };
  ostream& operator <<(ostream& out, const Edge& edge);
}

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

  //  Overloaded std::hash and << operator
  friend std::size_t std::hash<Edge>::operator()(const Edge& edge) const;
  friend std::ostream& operator<<(std::ostream& out, const Edge& edge);

private:
  Vertex from, to;
  std::string identifier;
  double value;
};

#endif // EDGE_H
