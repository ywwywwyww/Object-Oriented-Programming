/**
 * @file disjoint_set.cpp
 * @author Wuwei YUAN
 * @date 5/20/20
 */

#include "disjoint_set.h"

DisjointSet::DisjointSet(int n) : father_{}, rank_{} {
  this->father_.resize(n);
  this->rank_.resize(n);
  for (int i = 0; i < n; i++) {
    this->father_[i] = i;
    this->rank_[i] = 1;
  }
}

int DisjointSet::FindRoot(int x) {
  return this->father_[x] == x ? x : this->father_[x] = this->FindRoot(this->father_[x]);
}

void DisjointSet::Union(int x, int y) {
  x = this->FindRoot(x);
  y = this->FindRoot(y);
  if (x == y) {
    return;
  }
  if (this->rank_[x] == this->rank_[y]) {
    this->father_[x] = y;
    this->rank_[y]++;
  } else if (this->rank_[x] > this->rank_[y]) {
    this->father_[y] = x;
  } else {
    this->father_[x] = y;
  }
}