/**
 * @file delaunay_triangulation.cpp
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#include <map>
#include <CGAL/Delaunay_triangulation_2.h>
#include "delaunay_triangulation.h"

void DelaunayTriangulation::Construct(Graph *const &graph) const {
  std::map<Graph::Point, int> point_to_id;
  for (int i = 0; i < graph->GetNumVertices(); i++) {
    point_to_id[graph->GetVertex(i)] = i;
  }
  // Build Delaunay triangulation
  auto delaunay_triangulation = CGAL::Delaunay_triangulation_2<Graph::Kernel>(graph->GetVertices().begin(), graph->GetVertices().end());
  for (auto edge_iterator = delaunay_triangulation.finite_edges_begin(); edge_iterator != delaunay_triangulation.finite_edges_end(); edge_iterator++) {
    auto segment = delaunay_triangulation.segment(*edge_iterator);
    auto source = segment.source();
    int source_id = point_to_id[source];
    auto target = segment.target();
    int target_id = point_to_id[target];
    graph->AddEdge(Graph::Edge(source_id, target_id));
  }
}