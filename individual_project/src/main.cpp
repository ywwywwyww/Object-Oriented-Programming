#include <iostream>
#include <fstream>
#include "generator/generator.h"
#include "graph/complete_graph.h"
#include "graph/delaunay_triangulation.h"
#include "graph/kruskal.h"
#include "graph/construction_strategy.h"
#include "timer/timer.h"

/**
 * Constructs minimal spanning tree using given construction class and generated points and constraints
 * @tparam Construction The construction class
 * @param n Number of nodes
 * @param m Number of edges in constraints
 */
template<typename ConstructionStrategy>
void Test(int n, int m) {
  Timer timer;
  timer.start();
  auto strategy = std::shared_ptr<ConstructionStrategy>{new ConstructionStrategy{}};
  auto graph = Graph{Generator::GeneratePoints(n), strategy.get()};
  std::shared_ptr<Kruskal> kruskal = std::make_shared<Kruskal>(Generator::GenerateForest(n, m));
  std::cout << "n = " << n << " m = " << m << '\n';
  std::cout << "Overall Length: " << graph.OverallLength() << '\n';
  std::cout << "MST Length: " << Graph{graph.GetVertices(), kruskal.get()}.OverallLength() << '\n';
  std::cout << "Time: " << timer.time() << "s" << '\n' << std::endl;
}

/**
 * Constructs minimal spanning tree using given construction class, points and constraints
 * @tparam Construction The construction class
 * @param points The given points
 * @param constraints The give edges
 */
template<typename ConstructionStrategy>
void Test(const std::vector<Graph::Point> &points, const std::vector<Graph::Edge> &constraints) {
  Timer timer;
  timer.start();
  auto strategy = std::shared_ptr<ConstructionStrategy>{new ConstructionStrategy{}};
  auto graph = Graph{points, strategy.get()};
  auto kruskal = std::make_shared<Kruskal>(constraints);
  std::cout << "n = " << points.size() << " m = " << constraints.size() << '\n';
  std::cout << "Overall Length: " << graph.OverallLength() << '\n';
  std::cout << "MST Length: " << Graph{graph.GetVertices(), kruskal.get()}.OverallLength() << '\n';
  std::cout << "Time: " << timer.time() << "s" << '\n' << std::endl;
}

void Help() {
  std::cerr << "Usage: ./src [option]\n";
  std::cerr << "Options:\n";
  std::cerr << "  -h           Display this information\n";
  std::cerr << "  -g           Test construction algorithms using generated test cases\n";
  std::cerr << "  -i <file>    Test construction algorithms using test cases in <file>\n";
  exit(0);
}

void TestGeneratedTestCases() {
  std::cout << "Complete Graph:\n";
  Test<CompleteGraph>(10000, 10);
  std::cout << "Delaunay Triangulation:\n";
  Test<DelaunayTriangulation>(10000, 10);
  Test<DelaunayTriangulation>(100000, 10);
}

void TestTestCases(const char *file_name) {
  std::fstream f_in_test_cases(file_name);
  if (!f_in_test_cases) {
    std::cerr << "Cannot find test cases" << std::endl;
  }
  int n, m;
  int t = 0;
  while (f_in_test_cases >> n) {
    std::cout << "Test Case #" << ++t << ":\n";
    std::vector<Graph::Point> points;
    for (int i = 0; i < n; i++) {
      Graph::Point p;
      f_in_test_cases >> p;
      points.push_back(std::move(p));
    }
    f_in_test_cases >> m;
    std::vector<Graph::Edge> edges;
    for (int i = 0; i < m; i++) {
      int u, v;
      f_in_test_cases >> u >> v;
      edges.push_back(std::pair(u, v));
    }
    Test<CompleteGraph>(points, edges);
    Test<DelaunayTriangulation>(points, edges);
  }
}

int main(int argc, char **argv) {
  if (argc == 1) {
//    TestGeneratedTestCases();
    Help();
  } else if (argv[1][0] != '-' || strlen(argv[1]) != 2) {
    Help();
  } else {
    switch (argv[1][1]) {
      case 'h':
        Help();
        break;
      case 'g':
        if (argc != 2) {
          Help();
        } else {
          TestGeneratedTestCases();
        }
        break;
      case 'i':
        if (argc != 3) {
          Help();
        } else {
          TestTestCases(argv[2]);
        }
        break;
      default:
        Help();
        break;
    }
  }
  // Generate test case
//  std::ofstream f_out_test_case("test_case.txt");
//  Generator::GenerateData(f_out_test_case, 1000, 10, 5);
  return 0;
}
