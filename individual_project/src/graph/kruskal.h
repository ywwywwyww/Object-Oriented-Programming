/**
 * @file kruskal.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_MINIMAL_SPANNING_TREE_KRUSKAL_H_
#define SRC_MINIMAL_SPANNING_TREE_KRUSKAL_H_

#include "minimal_spanning_tree.h"

class Kruskal : public MinimalSpanningTree {
 public:
  explicit Kruskal(const std::vector<Graph::Edge> &constraints = std::vector<Graph::Edge>{}) : MinimalSpanningTree{constraints} {}

  void Construct(Graph *const &graph) const override;

};

#endif //SRC_MINIMAL_SPANNING_TREE_KRUSKAL_H_
