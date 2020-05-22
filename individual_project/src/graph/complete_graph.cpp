/**
 * @file complete_graph.cpp
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#include "complete_graph.h"
#include "graph.h"

void CompleteGraph::Construct(Graph *const &graph) const {
  for (int i = 0; i < graph->GetNumVertices(); i++) {
    for (int j = 0; j < i; j++) {
      graph->AddEdge(std::pair(i, j));
    }
  }
}