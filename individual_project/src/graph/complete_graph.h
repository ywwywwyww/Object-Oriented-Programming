/**
 * @file complete_graph.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_GRAPH_COMPLETE_GRAPH_H_
#define SRC_GRAPH_COMPLETE_GRAPH_H_

#include "construction_strategy.h"

class CompleteGraph : public ConstructionStrategy {
 public:
  /**
   * Construgy a complete graph of the vertices
   * @param graph The graph
   */
  void Construct(Graph *const &graph) const override;
};

#endif //SRC_GRAPH_COMPLETE_GRAPH_H_
