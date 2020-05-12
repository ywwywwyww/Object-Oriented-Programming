#ifndef ADAPTERSORT_H_
#define ADAPTERSORT_H_
#include <algorithm>
#include <queue>
#include <vector>

#include "Pizza.h"
#include "Sort.h"

struct cmpre {
  bool operator()(Pizza* a, Pizza* b) { return a->get_id() > b->get_id(); }
};

class AdapterSort : public Sort {
 public:
  virtual void sorting(std::vector<Pizza*>* pizzas) {
    std::priority_queue<Pizza*, std::vector<Pizza*>, cmpre> pq;
    for (auto i : *pizzas) pq.push(i);
    for (int i = 0; i < pizzas->size(); ++i) {
      (*pizzas)[i] = pq.top();
      pq.pop();
    }
  }
  virtual ~AdapterSort() = default;
};

#endif /* ADAPTERSORT_H_ */