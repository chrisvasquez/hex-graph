#include "vertex.h"

Vertex::Vertex(const Vertex& vertex)
{
  identifier = vertex.identifier;
  value = vertex.value;
}

double Vertex::get_value() const {
  return value;
}

void Vertex::set_value(double value) {
  this->value = value;
}

std::string Vertex::get_identifier() const {
  return "";
}

bool Vertex::operator ==(const Vertex& vertex) const {
  return identifier == vertex.identifier;
}

bool Vertex::operator <(const Vertex& vertex) const {
  return identifier < vertex.identifier;
}

std::size_t std::hash<Vertex>::operator ()(const Vertex& vertex) const {
  return 0;
}

std::ostream& operator <<(std::ostream& out, const Vertex& vertex) {
  //  out << "<Vertex(" << vertex.get_identifier() << ":" << vertex.get_value() << ">";
  return out;
}
