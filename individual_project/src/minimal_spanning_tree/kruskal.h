/**
 * @file kruskal.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_MINIMAL_SPANNING_TREE_KRUSKAL_H_
#define SRC_MINIMAL_SPANNING_TREE_KRUSKAL_H_

#include <algorithm>
#include "minimal_spanning_tree.h"

class Kruskal : public MinimalSpanningTree {
 public:
  /**
   * Construct a minimal spanning tree of given graph and constraints
   * @param graph The given graph
   * @param constraints The constraints edges
   */
  explicit Kruskal(const UndirectedGraph &graph, const std::vector<Edge> &constraints = std::vector<Edge>{});
};

#endif //SRC_MINIMAL_SPANNING_TREE_KRUSKAL_H_
