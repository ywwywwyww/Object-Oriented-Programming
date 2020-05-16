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
#include <memory>

/**
 * A heap to store and sort pizza
 * Uses strategy design style
 */
class PizzaHeap {
 public:
  explicit PizzaHeap(std::shared_ptr<Sorter> sorter);
  /**
   * Inserts a pizza to the heap
   * @param pizza The pizza to be inserted
   */
  void Insert(std::shared_ptr<Pizza> pizza);
  /**
   * Displays all the pizza in the heap
   * @param out The output stream
   */
  void Display(std::ostream &out = std::cout);
  /**
   * Sorts all the pizza in the heap in ascending order of id
   */
  void Sort();
 private:
  std::shared_ptr<Sorter> sorter_; // The sorter
  std::vector<std::shared_ptr<Pizza>> pizzas_; // The pizzas in the heap
};

#endif //PROBLEM1_PIZZA_HEAP_PIZZA_HEAP_H_
