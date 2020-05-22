/**
 * @file minimal_spanning_tree.h
 * @author Wuwei YUAN
 * @date 5/21/20
 */

#ifndef SRC_GRAPH_MINIMAL_SPANNING_TREE_H_
#define SRC_GRAPH_MINIMAL_SPANNING_TREE_H_

#include "construction_strategy.h"
#include "graph.h"

class MinimalSpanningTree : public ConstructionStrategy {
 public:
  /**
   * Construct a minimal spanning tree strategy with given constraints
   * @param constraints The constraint edges
   */
  explicit MinimalSpanningTree(const std::vector<Graph::Edge> &constraints = std::vector<Graph::Edge>{}) : constraints_{constraints} {}
 protected:
  std::vector<Graph::Edge> constraints_;
};

#endif //SRC_GRAPH_MINIMAL_SPANNING_TREE_H_
