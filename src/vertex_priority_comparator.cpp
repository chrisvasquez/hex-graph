#include "vertex_priority_comparator.h"

bool VertexPriorityComparator::operator() (const Vertex& lhs, const Vertex& rhs) const {
  if (graph != nullptr) {
      return graph->GetVertexValue(lhs) < graph->GetVertexValue(rhs);
    } else {
      return lhs.get_value() < rhs.get_value();
    }
}
