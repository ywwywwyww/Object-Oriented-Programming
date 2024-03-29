/**
 * @file kruskal.cpp
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#include <algorithm>
#include <CGAL/squared_distance_2.h>
#include "kruskal.h"
#include "disjoint_set.h"

void Kruskal::Construct(Graph *const &graph) const {

  int n = graph->GetNumVertices();
  DisjointSet disjoint_set{n};

  // Add constraints edges first
  graph->AddEdges(this->constraints_);
  for (auto edge : this->constraints_) {
    disjoint_set.Union(edge.first, edge.second);
  }

  // Sort the edges in ascending order of length
  std::vector<std::pair<int, int>> edges = graph->GetEdges();
  auto cmp = [&graph] (auto edge1, auto edge2) {
    auto distance1 = CGAL::squared_distance(graph->GetVertex(edge1.first), graph->GetVertex(edge1.second));
    auto distance2 = CGAL::squared_distance(graph->GetVertex(edge2.first), graph->GetVertex(edge2.second));
    return distance1 < distance2;
  };
  std::sort(edges.begin(), edges.end(), cmp);
  for (auto [u, v] : edges) {
    if (disjoint_set.FindRoot(u) != disjoint_set.FindRoot(v)) {
      disjoint_set.Union(u, v);
      graph->AddEdge(std::pair(u, v));
    }
  }
}