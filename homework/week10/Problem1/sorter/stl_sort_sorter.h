/**
 * @file stl_sort_sorter.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1_SORTER_STL_SORT_SORTER_H_
#define PROBLEM1_SORTER_STL_SORT_SORTER_H_

#include "sorter.h"

/**
 * A sorter class for sorting pizzas
 * Uses stl sort
 */
class StlSortSorter : public Sorter {
 public:
  /**
   * Sorts the given pizza vector using stl sort function
   * @param pizzas The pizza vector
   */
  void Sort(std::vector<std::shared_ptr<Pizza>> &pizzas) override;
};

#endif //PROBLEM1_SORTER_STL_SORT_SORTER_H_
