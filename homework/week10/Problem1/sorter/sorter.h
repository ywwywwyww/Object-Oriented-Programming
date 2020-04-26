/**
 * @file sorter.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1_SORTER_SORTER_H_
#define PROBLEM1_SORTER_SORTER_H_

#include "../pizza/pizza.h"
#include <vector>

class Sorter {
 public:
  virtual void Sort(std::vector<Pizza*> &pizzas) = 0;
};

#endif //PROBLEM1_SORTER_SORTER_H_
