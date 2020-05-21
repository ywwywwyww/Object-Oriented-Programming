/**
 * @file delaunay_triangulation.cpp
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#include <map>
#include <CGAL/Delaunay_triangulation_2.h>
#include "delaunay_triangulation.h"

DelaunayTriangulation::DelaunayTriangulation(const std::vector<Point> &vertices) : UndirectedGraph(vertices) {
  std::map<Point, int> point_to_id;
  for (int i = 0; i < this->vertices_.size(); i++) {
    point_to_id[this->vertices_[i]] = i;
  }
  auto delaunay_triangulation = CGAL::Delaunay_triangulation_2<UndirectedGraph::Kernel>(this->vertices_.begin(), this->vertices_.end());
  for (auto edge_iterator = delaunay_triangulation.finite_edges_begin(); edge_iterator != delaunay_triangulation.finite_edges_end(); edge_iterator++) {
    auto segment = delaunay_triangulation.segment(*edge_iterator);
    auto source = segment.source();
    int source_id = point_to_id[source];
    auto target = segment.target();
    int target_id = point_to_id[target];
    this->AddEdge(Edge(source_id, target_id));
  }
}