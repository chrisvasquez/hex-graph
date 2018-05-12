#include "vertex.h"

//  Copy constructor : basic
Vertex::Vertex(const Vertex& vertex)
{
  identifier = vertex.identifier;
  value = vertex.value;
}
//  Getter for value
double Vertex::get_value() const {
  return value;
}
//  Setter for value
void Vertex::set_value(double value) {
  this->value = value;
}
//  Getter for identifier
std::string Vertex::get_identifier() const {
  return identifier;
}
//  Setter for identifier
void Vertex::set_identifier(std::string identifier) {
  this->identifier = identifier;
}
//  Overload function definition of ==
bool Vertex::operator ==(const Vertex& vertex) const {
  return identifier == vertex.identifier;
}
//  Overload function definition of <
bool Vertex::operator <(const Vertex& vertex) const {
  return identifier < vertex.identifier;
}

// Custom class for use as the custom hash function for the Vertex class
// for use in unordered_map and unordered_set
std::size_t VertexHash::operator ()(const Vertex& vertex) const {
  return ((std::hash<std::string>()(vertex.get_identifier())) << 1 );
}

//  Overload definition for <<
std::ostream& operator <<(std::ostream& out, const Vertex& vertex) {
  out << "<Vertex(" << vertex.get_identifier() << ":" << vertex.get_value() << ">";
  return out;
}
