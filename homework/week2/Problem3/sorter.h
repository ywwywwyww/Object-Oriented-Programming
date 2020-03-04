//
// Created by yww on 3/4/20.
//

#ifndef PROBLEM3__SORTER_H_
#define PROBLEM3__SORTER_H_

class Sorter {
 public:
  /**
   * sort a[l,r] using quick sort
   * @param a the array
   * @param l
   * @param r
   */
  static void QuickSort(int* a, int l, int r);
  /**
   * sort a[l,r] using merge sort
   * @param a the array
   * @param l
   * @param r
   */
  static void MergeSort(int* a, int l, int r);
  /**
   * sort a[l,r] using bubble sort
   * @param a the array
   * @param l
   * @param r
   */
  static void BubbleSort(int *a, int l, int r);
};

#endif //PROBLEM3__SORTER_H_
