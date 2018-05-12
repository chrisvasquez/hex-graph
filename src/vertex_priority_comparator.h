#ifndef VERTEX_PRIORITY_COMPARATOR_H
#define VERTEX_PRIORITY_COMPARATOR_H

#include "graph.h"
#include "vertex.h"

class VertexPriorityComparator
{
public:
  VertexPriorityComparator() {};
  VertexPriorityComparator(Graph* graph): graph(graph) {};
  bool operator() (const Vertex& lhs, const Vertex& rhs) const;
private:
  Graph* graph;
};

#endif // VERTEX_PRIORITY_COMPARATOR_H
