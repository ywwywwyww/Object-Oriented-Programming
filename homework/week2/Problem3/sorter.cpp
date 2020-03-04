/**
 * @file sorter.cpp
 * @author Wuwei YUAN
 * @date 3/4/2020
 * Definition of sorting algorithms
 */

#include <vector>
#include "sorter.h"

/**
 * @ref https://appdividend.com/2019/05/02/quick-sort-in-c-tutorial-with-example-c-quick-sort-program/
 */
void Sorter::QuickSort(int *a, int l, int r) {
  if (l >= r) {
    return;
  }
  int pivot = a[r];
  int p_index = l;
  int i, t; // t is temporary variable
  // Here we will check if array value is less than pivot
  // then we will place it at left side by swapping
  for (i = l; i < r; i++) {
    if (a[i] <= pivot) {
      t = a[i];
      a[i] = a[p_index];
      a[p_index] = t;
      p_index++;
    }
  }
  // Now exchanging value of pivot and p-index
  t = a[r];
  a[r] = a[p_index];
  a[p_index] = t;
  // Separately sort elements before pivot and after pivot
  QuickSort(a, l, p_index - 1);
  QuickSort(a, p_index + 1, r);
}

void Sorter::MergeSort(int *a, int l, int r) {
  if (l >= r) {
    return;
  }
  // Divide
  int mid = (l + r) / 2;
  MergeSort(a, l, mid);
  MergeSort(a, mid+1, r);
  // Conquer - merge two sorted arrays into one
  std::vector<int> b;
  b.resize(r - l + 1);
  int t = 0, t1 = l, t2 = mid + 1;
  while(t1 <= mid || t2 <= r) {
    if (t2 > r || (t1 <= mid && a[t1] <= a[t2])) {
      b[t++] = a[t1++];
    } else {
      b[t++] = a[t2++];
    }
  }
  for (int i = l; i <= r; i++) {
    a[i] = b[i - l];
  }
}

void Sorter::BubbleSort(int *a, int l, int r) {
  // There are n-1 turns
  for (int i = r - 1; i >= l; i--) {
    // In each turn, swap the maximum element to the back
    for (int j = l; j < r; j++) {
      if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
      }
    }
  }
}