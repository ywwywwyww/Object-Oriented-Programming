/**
 * @file sorter.cpp
 * @author Wuwei YUAN
 * @date 3/4/2020
 * Definition of sorting algorithms
 */

#include <vector>
#include "sorter.h"
#include <algorithm>
#include "timer.h"

/**
 * @ref https://appdividend.com/2019/05/02/quick-sort-in-c-tutorial-with-example-c-quick-sort-program/
 */
void Sorter::QuickSort(std::vector<int> &a, int l, int r) {
  r--;
  if (l >= r) {
    return;
  }
  int pivot = a[r];
  int p_index = l;

  // Here we will check if array value is less than pivot
  // then we will place it at left side by swapping
  for (auto i = l; i < r; i++) {
    if (a[i] <= pivot) {
      std::swap(a[i], a[p_index]);
      p_index++;
    }
  }

  // Now exchanging value of pivot and p-index
  std::swap(a[r], a[p_index]);

  // Separately sort elements before pivot and after pivot
  QuickSort(a, l, p_index - 1);
  QuickSort(a, p_index + 1, r);
}

void Sorter::SelectionSort(std::vector<int> &a, int l, int r) {
  r--;
  for (int i = l; i < r; i++) {
    for (int j = i + 1; j <= r; j++) {
      if (a[i] > a[j]) {
        std::swap(a[i], a[j]);
      }
    }
  }
}

void Sorter::BubbleSort(std::vector<int> &a, int l, int r) {
  r--;
  // There are n-1 turns
  for (int i = r - 1; i >= l; i--) {
    // In each turn, swap the maximum element to the back
    for (int j = l; j < r; j++) {
      if (a[j] > a[j+1]) {
        std::swap(a[j], a[j+1]);
      }
    }
  }
}

std::vector<int> Sorter::GenerateRandomPermutation(int length) {
  std::vector<int> result;
  for (int i = 0; i < length; i++) {
    result.push_back(i);
  }
  for (int i = 0; i < length; i++) {
    std::swap(result[rand() % (i + 1)], result[i]);
  }
  return result;
}

double Sorter::Test(void (*sort_function)(std::vector<int>&, int, int), std::vector<int> input) {
  Timer timer{};
  timer.Start();
  sort_function(input, 0, input.size());
  return timer.Stop();
}