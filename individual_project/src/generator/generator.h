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
  static std::vector<Graph::Point> GeneratePoints(int n);
  static std::vector<Graph::Edge> GenerateForest(int n, int m);
  static void GenerateData(std::ostream &out, int n, int m, int t=1);
  static int kMin;
  static int kMax;
};

#endif //SRC_GENERATOR_GENERATOR_H_
