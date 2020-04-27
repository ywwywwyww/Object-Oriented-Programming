/**
* @file stl_priority_queue_sorter.h
* @author Wuwei YUAN
* @date 4/26/20
*/

#ifndef PROBLEM1_SORTER_STL_PRIORITY_QUEUE_SORTER_H_
#define PROBLEM1_SORTER_STL_PRIORITY_QUEUE_SORTER_H_

#include "sorter.h"
#include <queue>
#include <algorithm>

/**
 * The sorter class for sorting pizzas
 * Uses adapter design style
 */
class StlPriorityQueueSorter : public Sorter {
 public:
  /**
   * Sorts the pizza vector using stl priority queue
   * @param pizzas The pizza vector
   */
  void Sort(std::vector<Pizza *> &pizzas) override;
 private:
  /**
   * The functor for comparing
   * @tparam T Class Pizza
   */
  template<typename T>
  class PizzaCmp {
   public:
    bool operator()(const T &a, const T &b) {
      return a->GetId() > b->GetId();
    }
  };
  std::priority_queue<Pizza *, std::vector<Pizza *>, StlPriorityQueueSorter::PizzaCmp<Pizza *> > priority_queue_;
};

#endif //PROBLEM1_SORTER_STL_PRIORITY_QUEUE_SORTER_H_
