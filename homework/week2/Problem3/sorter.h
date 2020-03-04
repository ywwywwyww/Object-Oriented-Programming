/**
 * @file sorter.h
 * @author Wuwei YUAN
 * @date 3/4/2020
 */

#ifndef PROBLEM3__SORTER_H_
#define PROBLEM3__SORTER_H_

/**
 * A sorter contains three different sorting algorithms
 * Example:
 *    int a[100];
 *    Sorter::QuickSort(a, 0, 1);
 */
class Sorter {
 public:
  /**
   * Sorts elements in the range [l,r] of a array in ascending order using quick sort
   * @param a The pointer to the array
   * @param l The left endpoint
   * @param r The right endpoint
   */
  static void QuickSort(int* a, int l, int r);
  /**
   * Sorts elements in the range [l,r] of a array in ascending order using merge sort
   * @param a The pointer to the array
   * @param l The left endpoint
   * @param r The right endpoint
   */
  static void MergeSort(int* a, int l, int r);
  /**
   * Sorts elements in the range [l,r] of a array in ascending order using bubble sort
   * @param a The pointer to the array
   * @param l The left endpoint
   * @param r The right endpoint
   */
  static void BubbleSort(int *a, int l, int r);
};

#endif //PROBLEM3__SORTER_H_
