/**
 * @file minimal_spanning_tree.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_MINIMAL_SPANNING_TREE_MINIMAL_SPANNING_TREE_H_
#define SRC_MINIMAL_SPANNING_TREE_MINIMAL_SPANNING_TREE_H_

#include "../graph/undirected_graph.h"

class MinimalSpanningTree : public UndirectedGraph {
 public:
  explicit MinimalSpanningTree(const std::vector<Point> &vertices, const std::vector<Edge> &edges = std::vector<Edge>{})
      : UndirectedGraph{vertices, edges} {}
};

#endif //SRC_MINIMAL_SPANNING_TREE_MINIMAL_SPANNING_TREE_H_
