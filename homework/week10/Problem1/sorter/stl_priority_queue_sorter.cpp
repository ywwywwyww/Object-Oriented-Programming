/**
 * @file stl_priority_queue_sorter.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "stl_priority_queue_sorter.h"

void StlPriorityQueueSorter::Sort(std::vector<Pizza *> &pizzas) {
  while (!(this->priority_queue_.empty())) {
    this->priority_queue_.pop();
  }
  for (auto pizza : pizzas) {
    this->priority_queue_.push(pizza);
  }
  for (auto &pizza : pizzas) {
    pizza = this->priority_queue_.top();
    this->priority_queue_.pop();
  }
}