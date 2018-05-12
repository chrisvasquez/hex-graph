#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <string>

//
//  Class Vertex
//    *  Designed to be sub-classed to make a more appropriate class name for the application
//       being developed, like class Intersection in terms of maps
//    *  The get_value() function, overloaded can give a more meaningful and rich sub-class
class Vertex
{
public:
  //  Constructor with default parameter values
  //  Acts as the default constructor
  Vertex(std::string identifier = "", double value = 0): identifier(identifier), value(value) {}
  //  Copy constructor
  Vertex(const Vertex& vertex);
  //  Setter and getter for identifier
  void set_identifier(std::string);
  std::string get_identifier() const;
  //  Setter and getter for value
  void set_value(double value);
  double get_value() const;
  //  Overloaded === and < operators
  bool operator ==(const Vertex& vertex) const;
  bool operator <(const Vertex& vertex) const;
  //  Overloaded std::hash and << operator
  friend std::ostream& operator<<(std::ostream& out, const Vertex& vertex);
private:
  //  String identifier for the vertex, maybe the name of the vertex
  //  Can also use a uuid, or an automatically generated uuid if on construction there is no passed
  //  identifier as a parameter
  std::string identifier;
  //  Value of the vertex that can be used in computation in a graph algorithm
  double value;
};

// Custom class for use as the custom hash function for the Vertex class
// for use in unordered_map and unordered_set
class VertexHash {
public:
    std::size_t operator()(const Vertex& vertex) const;
};

#endif // VERTEX_H
