/**
 * @file customed_sorter.h
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#ifndef PROBLEM1_SORTER_CUSTOM_SORTER_H_
#define PROBLEM1_SORTER_CUSTOM_SORTER_H_

#include "sorter.h"

/**
 * A sorter class for sorting pizzas
 * Uses custom sorting function
 */
class CustomSorter : public Sorter {
 private:
  void Sort(std::vector<std::shared_ptr<Pizza>> &pizzas) override;
};

#endif //PROBLEM1_SORTER_CUSTOM_SORTER_H_
