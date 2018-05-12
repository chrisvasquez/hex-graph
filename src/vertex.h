#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <string>

//  Forward declaration of the class for use in the definition of the overloaded
//  std::hash and the << operator
class Vertex;

//  Declaration of the overloaded std::hash and << operator
namespace std {
  template <>
  struct hash<Vertex> {
    size_t operator ()(const Vertex& vertex) const;
  };
  ostream& operator <<(ostream& out, const Vertex& vertex);
}

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
  Vertex(std::string identifier = "", double value = 0): identifier(identifier), value(value) {};
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
  friend std::size_t std::hash<Vertex>::operator()(const Vertex& vertex) const;
  friend std::ostream& operator<<(std::ostream& out, const Vertex& vertex);
private:
  //  String identifier for the vertex, maybe the name of the vertex
  //  Can also use a uuid, or an automatically generated uuid if on construction there is no passed
  //  identifier as a parameter
  std::string identifier;
  //  Value of the vertex that can be used in computation in a graph algorithm
  double value;
};

#endif // VERTEX_H
