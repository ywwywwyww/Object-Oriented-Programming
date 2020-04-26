/**
 * @file pizza_heap.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1_PIZZA_HEAP_PIZZA_HEAP_H_
#define PROBLEM1_PIZZA_HEAP_PIZZA_HEAP_H_

#include <vector>
#include <iostream>
#include "../pizza/pizza.h"
#include "../sorter/sorter.h"

class PizzaHeap {
 public:
  PizzaHeap(Sorter *sorter);
  void Insert(Pizza *pizza);
  void Display(std::ostream &out = std::cout);
  void Sort();
 private:
  Sorter *sorter_;
  std::vector<Pizza*> pizzas_;
};

#endif //PROBLEM1_PIZZA_HEAP_PIZZA_HEAP_H_
