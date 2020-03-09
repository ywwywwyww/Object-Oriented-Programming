/**
 * @file sorter.h
 * @author Wuwei YUAN
 * @date 3/4/2020
 */

#ifndef PROBLEM3__SORTER_H_
#define PROBLEM3__SORTER_H_

#include <vector>

/**
 * A sorter contains three different sorting algorithms
 * Example:
 *    int a[100];
 *    Sorter::QuickSort(a, 0, 1);
 */
class Sorter {
 public:
  /**
   * Sorts elements in the range [l, r) of a vector in ascending order using quick sort
   * @param a The vector
   * @param l, r The range of elements to sort
   */
  static void QuickSort(std::vector<int> &a, int l, int r);
  /**
   * Sorts elements in the range [l, r) of a vector in ascending order using selection sort
   * @param a The vector
   * @param l, r The range of elements to sort
   */
  static void SelectionSort(std::vector<int> &a, int l, int r);
  /**
   * Sorts elements in the range [l, r) of a vector in ascending order using bubble sort
   * @param a The vector
   * @param l, r The range of elements to sort
   */
  static void BubbleSort(std::vector<int> &a, int l, int r);
  /**
   * Generates a random permutation
   * @param length The length of permutation
   * @return The generated random permutation
   */
  static std::vector<int> GenerateRandomPermutation(int length);
};

#endif //PROBLEM3__SORTER_H_
