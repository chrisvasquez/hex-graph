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

  //  Getters and Setters
  Vertex get_from() const;
  void set_from(const Vertex& from);
  Vertex get_to() const;
  void set_to(const Vertex& to);
  std::string get_identifier() const;
  void set_identifier(std::string identifier);
  double get_value() const;
  void set_value(double value);

  //  Overloaded relational operators
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
