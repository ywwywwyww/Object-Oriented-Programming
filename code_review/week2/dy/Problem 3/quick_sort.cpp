/**
 * @file				quick_sort.cpp
 * @author				Yan DAI
 * @date				Feb 26, 2020
 *
 * Implements quick sort algorithm.
 */

#include "sorter.h"
#include <algorithm> // For `std::swap` function

/**
 * Implements quick sort for class `Sorter`:
 *
 * Divide and conquer. In each recursion, do the following:
 * - First, randomly pick a pivot `p`.
 * - Then place the elements less or equal to p to the left,
 *   those grater than p to the right.
 * - At last, sort the left and right part separately.
 *
 * @param arr The array to be sorted.
 */
void Sorter::quick_sort(std::vector<int> &arr)
{
	quick_sort_helper(arr, 0, arr.size() - 1);
}

/**
 * Implements the divide and conquer part of
 * quick sort algorithm.
 *
 * @param arr   The array to be sorted.
 * @param left  The left boundary of this recursion.
 * @param right The right boundary of this recursion.
 */
void Sorter::quick_sort_helper(std::vector<int> &arr,
							   int left, int right)
{
	// If there is only no more than one element,
	// we have already finished sorting!
	if (left >= right)
		return;

	// Randomly pick the pivot
	int pivot_index = generate_random(left, right);
	int pivot_value = arr[pivot_index];
	// Swap it to the end, in order to do an in-place sorting.
	std::swap(arr[pivot_index], arr[right]);

	int first_unused = left;
	for (int i = left; i < right; i++)
	{
		if (arr[i] <= pivot_value)
		{
			std::swap(arr[first_unused], arr[i]);
			first_unused++;
		}
	}
	std::swap(arr[right], arr[first_unused]);

	quick_sort_helper(arr, left, first_unused - 1);
	quick_sort_helper(arr, first_unused + 1, right);
}
