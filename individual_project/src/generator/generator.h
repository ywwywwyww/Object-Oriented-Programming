/**
 * @file generator.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_GENERATOR_GENERATOR_H_
#define SRC_GENERATOR_GENERATOR_H_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../graph/graph.h"

class Generator {
 public:
  Generator() {
    srand(time(0));
  }
  /**
   * Generates n individual points on the plane
   * @param n The number of points
   * @return The points
   */
  static std::vector<Graph::Point> GeneratePoints(int n);
  /**
   * Generates a forest of m edges on n vertices
   * @param n The number of vertices
   * @param m The number of edges
   * @return The edges
   */
  static std::vector<Graph::Edge> GenerateForest(int n, int m);
  /**
   * Generates and outputs t test cases to the output stream
   * @param out The output stream
   * @param n The number of vertices
   * @param m The number of edges
   * @param t The number of test cases
   */
  static void GenerateData(std::ostream &out, int n, int m, int t=1);
  static int kMin; // The minimal number of coordinate, default=1
  static int kMax; // The maximal number of coordinate, default=1e9
};

#endif //SRC_GENERATOR_GENERATOR_H_
