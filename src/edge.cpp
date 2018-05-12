#include "edge.h"

//  Getters and Setters
Vertex Edge::get_from() const {
  return from;
}

void Edge::set_from(const Vertex& from) {
  this->from = from;
}

Vertex Edge::get_to() const {
  return to;
}

void Edge::set_to(const Vertex& to) {
  this->to = to;
}

std::string Edge::get_identifier() const {
  return identifier;
}

void Edge::set_identifier(std::string identifier) {
  this->identifier = identifier;
}

double Edge::get_value() const {
  return value;
}

void Edge::set_value(double value) {
  this->value = value;
}

//  Overload of the == operator
bool Edge::operator ==(const Edge& edge) const {
  return identifier == edge.identifier;
}

//  Overload of the < operator
bool Edge::operator <(const Edge& edge) const {
  return identifier < edge.identifier;
}

// Custom class for use as the custom hash function for the Edge class
// for use in unordered_map and unordered_set
std::size_t EdgeHash::operator ()(const Edge& edge) const {
  return (std::hash<std::string>()(edge.get_identifier()) << 1);
}

//  Overload definition for <<
std::ostream& operator <<(std::ostream& out, const Edge& edge) {
  out << "<Edge( Id: " << edge.get_identifier()
      << edge.get_from() << " to " << edge.get_to()
      << "Value : " << edge.get_value() << ")>";
  return out;
}
