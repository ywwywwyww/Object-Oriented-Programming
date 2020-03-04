/**
 * @file main.cpp
 * @author Wuwei YUAN
 * @date 3/4/2020
 */

#include "sorter.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iostream>
#include "timer.h"
#include <iomanip>

int main() {
  // Set random seed
  srand(time(NULL));

  // Generate random array
  int n = 10000;
  static int a[1000000], b[1000000], c[1000000];
  for (int i = 0; i < n; i++) {
    a[i] = b[i] = c[i] = rand();
  }

  // Sort
  Timer timer{};
  timer.Start();
  Sorter::BubbleSort(a, 0, n - 1);
  double bubble_sort_time = timer.Stop();
  timer.Start();
  Sorter::MergeSort(b, 0, n - 1);
  double merge_sort_time = timer.Stop();
  timer.Start();
  Sorter::QuickSort(c, 0, n - 1);
  double quick_sort_time = timer.Stop();
  // Check whether bubble_sort_time is too small to avoid divide-by-zero error
  double merge_sort_improvement = (bubble_sort_time < 1e-9 ? 0 : (bubble_sort_time - merge_sort_time) / bubble_sort_time);
  double quick_sort_improvement = (bubble_sort_time < 1e-9 ? 0 : (bubble_sort_time - quick_sort_time) / bubble_sort_time);

  // Output
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "bubble sort: " << bubble_sort_time << "s\n";
  std::cout << "merge sort: " << merge_sort_time << "s  improvement: " << merge_sort_improvement * 100 << "%\n";
  std::cout << "quick sort: " << quick_sort_time << "s  improvement: " << quick_sort_improvement * 100 << "%\n";
  return 0;
}