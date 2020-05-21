/**
 * @file delaunay_triangulation.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_GRAPH_DELAUNAY_TRIANGULATION_H_
#define SRC_GRAPH_DELAUNAY_TRIANGULATION_H_

#include "undirected_graph.h"

class DelaunayTriangulation : public UndirectedGraph {
 public:
  explicit DelaunayTriangulation(const std::vector<Point> &vertices);
};

#endif //SRC_GRAPH_DELAUNAY_TRIANGULATION_H_
