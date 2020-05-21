/**
 * @file complete_graph.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_GRAPH_COMPLETE_GRAPH_H_
#define SRC_GRAPH_COMPLETE_GRAPH_H_

#include "undirected_graph.h"

class CompleteGraph : public UndirectedGraph {
 public:
  explicit CompleteGraph(const std::vector<Point> &vertices);
};

#endif //SRC_GRAPH_COMPLETE_GRAPH_H_
