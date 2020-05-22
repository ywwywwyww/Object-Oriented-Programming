/**
 * @file generator.cpp
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#include <set>
#include "generator.h"
#include "../graph/disjoint_set.h"

Generator Initializer{};

int Generator::kMin = 1;
int Generator::kMax = 1000000000;

std::vector<Graph::Point> Generator::GeneratePoints(int n) {
  std::set<Graph::Point> set;
  std::vector<Graph::Point> result;
  for (int i = 0; i < n; i++) {
    Graph::Point point;
    do {
      point = Graph::Point{rand() % (kMax - kMin + 1) + kMin, rand() % (kMax - kMin + 1) + kMin};
    } while(set.count(point));
    set.insert(point);
    result.push_back(point);
  }
  return result;
}

std::vector<Graph::Edge> Generator::GenerateForest(int n, int m) {
  DisjointSet disjoint_set{n};
  std::vector<Graph::Edge> result;
  for (int i = 0; i < m; i++) {
    int u, v;
    do {
      u = rand() % n;
      v = rand() % n;
    } while(disjoint_set.FindRoot(u) == disjoint_set.FindRoot(v));
    disjoint_set.Union(u, v);
    result.push_back(std::pair(u, v));
  }
  return result;
}

void Generator::GenerateData(std::ostream &out, int n, int m, int t) {
  while(t--) {
    auto points = Generator::GeneratePoints(n);
    out << n << '\n';
    for (const auto &point : points) {
      out << int(CGAL::to_double(point.x()) + 0.5) << ' ' << int(CGAL::to_double(point.y()) + 0.5) << '\n';
    }

    auto constraints = Generator::GenerateForest(n, m);
    out << m << '\n';
    for (auto [u, v] : constraints) {
      out << u << ' ' << v << '\n';
    }
  }
  out << std::flush;
}