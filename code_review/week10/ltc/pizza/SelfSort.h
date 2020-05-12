#ifndef SELFSORT_H_
#define SELFSORT_H_

#include <algorithm>

#include "Pizza.h"
#include "Sort.h"

bool cmpr(Pizza* a, Pizza* b) { return a->get_id() < b->get_id(); }

class SelfSort : public Sort {
 public:
  // using bubble sort algorithm
  virtual void sorting(std::vector<Pizza*>* pizzas) {
    int n = pizzas->size();
    for (int i = 0; i < n; ++i)
      for (int j = n - 2; j >= i; --j)
        if (cmpr((*pizzas)[j + 1], (*pizzas)[j]))
          std::swap((*pizzas)[j + 1], (*pizzas)[j]);
  }
  virtual ~SelfSort() = default;
};

#endif /* SELFSORT_H_ */