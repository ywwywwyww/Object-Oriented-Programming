/**
 * @file graph_adapter.h
 * @author Wuwei YUAN
 * @date 5/21/20
 */

#ifndef SRC_GRAPH_CONSTRUCTION_STRATEGY_H_
#define SRC_GRAPH_CONSTRUCTION_STRATEGY_H_

#include <memory>

class Graph;

class ConstructionStrategy {
 public:
  ConstructionStrategy() = default;
  virtual void Construct(Graph *const &graph) const = 0;
};

#endif //SRC_GRAPH_CONSTRUCTION_STRATEGY_H_
