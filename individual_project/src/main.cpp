#include <iostream>
#include <fstream>
#include "generator/generator.h"
#include "graph/complete_graph.h"
#include "graph/delaunay_triangulation.h"
#include "minimal_spanning_tree/kruskal.h"
#include "timer/timer.h"

/**
 * Constructs minimal spanning tree using given construction class and generated points and constraints
 * @tparam Construction The construction class
 * @param n Number of nodes
 * @param m Number of edges in constraints
 */
template<typename Construction>
void Test(int n, int m) {
  Timer timer;
  timer.start();
  auto graph = Construction{Generator::GeneratePoints(n)};
  std::cout << "n = " << n << " m = " << m << '\n';
  std::cout << "Overall Length: " << graph.OverallLength() << '\n';
  std::cout << "MST Length: " << Kruskal{graph, Generator::GenerateForest(n, m)}.OverallLength() << '\n';
  std::cout << "Time: " << timer.time() << "s" << '\n' << std::endl;
}

/**
 * Constructs minimal spanning tree using given construction class, points and constraints
 * @tparam Construction The construction class
 * @param points The given points
 * @param constraints The give edges
 */
template<typename Construction>
void Test(const std::vector<UndirectedGraph::Point> &points, const std::vector<UndirectedGraph::Edge> &constraints) {
  Timer timer;
  timer.start();
  auto graph = Construction{points};
  std::cout << "n = " << points.size() << " m = " << constraints.size() << '\n';
  std::cout << "Overall Length: " << graph.OverallLength() << '\n';
  std::cout << "MST Length: " << Kruskal{graph, constraints}.OverallLength() << '\n';
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
  Test<CompleteGraph>(1000, 10);
  std::cout << "Delaunay Triangulation:\n";
  Test<DelaunayTriangulation>(1000, 10);
  Test<DelaunayTriangulation>(10000, 10);
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
    std::vector<UndirectedGraph::Point> points;
    for (int i = 0; i < n; i++) {
      UndirectedGraph::Point p;
      f_in_test_cases >> p;
      points.push_back(std::move(p));
    }
    f_in_test_cases >> m;
    std::vector<UndirectedGraph::Edge> edges;
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
