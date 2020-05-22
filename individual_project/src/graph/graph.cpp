/**
 * @file graph.cpp
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#include <CGAL/squared_distance_2.h>
#include "graph.h"
#include "construction_strategy.h"

Graph::Graph(std::istream &in) : vertices_{}, edges_{} {
  int n, m;
  in >> n >> m;
  for (int i = 0; i < n; i++) {
    Point p;
    in >> p;
    this->vertices_.push_back(std::move(p));
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    in >> u >> v;
    this->AddEdge(std::pair(u, v));
  }
}

Graph::Graph(const std::vector<Point> &vertices, ConstructionStrategy *const &strategy) : Graph{vertices} {
  strategy->Construct(this);
}

void Graph::AddEdge(const Graph::Edge &edge) {
  this->edges_.push_back(edge);
}

void Graph::AddEdges(const std::vector<Edge> &edges) {
  for (const Edge &edge : edges) {
    this->AddEdge(edge);
  }
}

double Graph::OverallLength() const {
  double sum = 0;
  for (auto[u, v] : this->edges_) {
    sum += std::sqrt(CGAL::to_double(CGAL::squared_distance(this->vertices_[u], this->vertices_[v])));
  }
  return sum;
}

void Graph::DisplayVertices(std::ostream &out) const {
  out << this->vertices_.size() << '\n';
  for (const auto &vertex : this->vertices_) {
    out << int(CGAL::to_double(vertex.x()) + 0.5) << ' ' << int(CGAL::to_double(vertex.y()) + 0.5) << '\n';
  }
  out << std::flush;
}

void Graph::DisplayEdges(std::ostream &out) const {
  out << this->edges_.size() << '\n';
  for (auto[u, v] : this->edges_) {
    out << u << ' ' << v << '\n';
  }
  out << std::flush;
}

std::ostream &operator<<(std::ostream &out, const Graph &graph) {
  out << graph.GetNumVertices() << '\n';
  for (const Graph::Point &vertex : graph.GetVertices()) {
    out << int(CGAL::to_double(vertex.x()) + 0.5) << ' ' << int(CGAL::to_double(vertex.y()) + 0.5) << '\n';
  }
  out << graph.GetNumEdges() << '\n';
  for (const Graph::Edge &edge : graph.GetEdges()) {
    out << edge.first << ' ' << edge.second << '\n';
  }
  out << std::flush;
  return out;
}