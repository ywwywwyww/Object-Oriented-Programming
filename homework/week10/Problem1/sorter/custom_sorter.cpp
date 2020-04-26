/**
 * @file customed_sorter.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "custom_sorter.h"
#include <algorithm>

void CustomSorter::Sort(std::vector<Pizza *> &pizzas) {
  for (int length = pizzas.size(), i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (pizzas[i]->GetId() > pizzas[j]->GetId()) {
        std::swap(pizzas[i], pizzas[j]);
      }
    }
  }
}