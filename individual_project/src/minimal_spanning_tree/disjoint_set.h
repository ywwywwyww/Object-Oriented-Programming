/**
 * @file disjoint_set.h
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#ifndef SRC_MINIMAL_SPANNING_TREE_DISJOINT_SET_H_
#define SRC_MINIMAL_SPANNING_TREE_DISJOINT_SET_H_

#include <vector>

class DisjointSet {
 public:
  /**
   * Create a disjoint set with n nodes
   * @param n Number of nodes
   */
  explicit DisjointSet(int n);
  int FindRoot(int x);
  void Union(int x, int y);
 private:
  std::vector<int> father_;
  std::vector<int> rank_;
};

#endif //SRC_MINIMAL_SPANNING_TREE_DISJOINT_SET_H_
