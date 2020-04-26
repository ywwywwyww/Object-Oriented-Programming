/**
 * @file stl_sort_sorter.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "stl_sort_sorter.h"
#include <algorithm>

void StlSortSorter::Sort(std::vector<Pizza *> &pizzas) {
  auto pizza_cmp = [](auto a, auto b) {return a->GetId() < b->GetId();};
  sort(pizzas.begin(), pizzas.end(), pizza_cmp);
}