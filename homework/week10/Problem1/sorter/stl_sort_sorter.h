/**
 * @file stl_sort_sorter.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1_SORTER_STL_SORT_SORTER_H_
#define PROBLEM1_SORTER_STL_SORT_SORTER_H_

#include "sorter.h"

class StlSortSorter : public Sorter {
 public:
  void Sort(std::vector<Pizza*> &pizzas) override;
};

#endif //PROBLEM1_SORTER_STL_SORT_SORTER_H_
