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
//  Template specialization for the type Vertex of std::hash::operator()
//  For use in unordered_map or unordered_set
std::size_t std::hash<Vertex>::operator ()(const Vertex& vertex) const {
  return 0;
}
//  Overload definition for <<
std::ostream& operator <<(std::ostream& out, const Vertex& vertex) {
  out << "<Vertex(" << vertex.get_identifier() << ":" << vertex.get_value() << ">";
  return out;
}
