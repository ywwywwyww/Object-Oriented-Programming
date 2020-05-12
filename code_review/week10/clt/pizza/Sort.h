#ifndef SORT_H_
#define SORT_H_

#include <vector>

class Pizza;
class Sort {
  // The interface of all sort classes, the virtual sorting function will be
  // implemented in different sort classed using different sorting algorithms.
 public:
  Sort() = default;
  virtual void sorting(std::vector<Pizza *> *pizzas) = 0;
  virtual ~Sort() = default;
};

#endif /* SORT_H_ */