#ifndef STLSORT_H_
#define STLSORT_H_

#include <algorithm>  //std::sort

#include "Pizza.h"
#include "Sort.h"

bool cmpre(const Pizza* a, const Pizza* b) { return a->get_id() < b->get_id(); }

class STLSort : public Sort {
 public:
  virtual void sorting(std::vector<Pizza*>* pizzas) {
    std::sort(pizzas->begin(), pizzas->end(), cmpre);
  }

  virtual ~STLSort() = default;
};

#endif /* STLSORT_H_ */