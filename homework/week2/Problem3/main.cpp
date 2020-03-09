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
#include <algorithm>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./Problem3 <length of tested permutation>" << std::endl;
    return -1;
  }
  // Set random seed
  srand(time(NULL));

  // Generate random array
  int n = atoi(argv[1]);
  std::vector<int> data = Sorter::GenerateRandomPermutation(n);

  // Sort
  Timer timer{};
  std::vector<int> input = data;
  timer.Start();
  Sorter::BubbleSort(input, 0, n);
  double bubble_sort_time = timer.Stop();
  input = data;
  timer.Start();
  Sorter::SelectionSort(input, 0, n);
  double selection_sort_time = timer.Stop();
  input = data;
  timer.Start();
  Sorter::QuickSort(input, 0, n);
  double quick_sort_time = timer.Stop();
  // Check whether bubble_sort_time is too small to avoid divide-by-zero error
  double baseline_time = std::max({bubble_sort_time, selection_sort_time, quick_sort_time});
  double bubble_sort_improvement = (baseline_time < 1e-9? 0 : (baseline_time - bubble_sort_time) / baseline_time);
  double selection_sort_improvement = (baseline_time < 1e-9 ? 0 : (baseline_time - selection_sort_time) / baseline_time);
  double quick_sort_improvement = (baseline_time < 1e-9 ? 0 : (baseline_time - quick_sort_time) / baseline_time);

  // Output
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "baseline: " << baseline_time << "s" << std::endl;
  std::cout << "bubble sort: " << bubble_sort_time << "s improvement: " << bubble_sort_improvement * 100 << "%" << std::endl;
  std::cout << "selection sort: " << selection_sort_time << "s  improvement: " << selection_sort_improvement * 100 << "%" << std::endl;
  std::cout << "quick sort: " << quick_sort_time << "s  improvement: " << quick_sort_improvement * 100 << "%" << std::endl;
  return 0;
}