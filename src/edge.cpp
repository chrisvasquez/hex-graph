#include "edge.h"

Edge::Edge()
{

}

//  Template specialization for the type Edge of std::hash::operator()
//  For use in unordered_map or unordered_set
std::size_t EdgeHash::operator ()(const Edge& edge) const {
  return 0;
  // return (((std::hash<edge<EdgeCost, VertexIdentifier, VertexValue> >()(e)) << 1 ) >> 1);
}
//  Overload definition for <<
std::ostream& operator <<(std::ostream& out, const Edge& edge) {
  out << "<Edge(" << ">";
  return out;
}
