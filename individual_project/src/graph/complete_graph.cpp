/**
 * @file complete_graph.cpp
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#include "complete_graph.h"

CompleteGraph::CompleteGraph(const std::vector<Point> &vertices) : UndirectedGraph(vertices) {
  for (int i = 0; i < this->vertices_.size(); i++) {
    for (int j = 0; j < i; j++) {
      this->edges_.emplace_back(i, j);
    }
  }
}