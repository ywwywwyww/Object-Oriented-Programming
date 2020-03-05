/**
 * @file				merge_sort.cpp
 * @author				Yan DAI
 * @date				Feb 26, 2020
 *
 * Implements merge sort algorithm.
 */

#include "sorter.h"

/**
 * Implements merge sort for class `Sorter`:
 *
 * Divide and conquer. In each recursion, do the following:
 * - Sort the left and right part separately.
 * - Then merge them.
 *
 * @param arr The array to be sorted.
 */
void Sorter::merge_sort(std::vector<int> &arr)
{
	merge_sort_helper(arr, 0, arr.size() - 1);
}

/**
 * Implements the divide and conquer part of
 * merge sort algorithm.
 *
 * @param arr   The array to be sorted.
 * @param left  The left boundary of this recursion.
 * @param right The right boundary of this recursion.
 */
void Sorter::merge_sort_helper(std::vector<int> &arr,
							   int left, int right)
{
	// If there is only no more than one element,
	// we have already finished sorting!
	if (left >= right)
		return;

	// Pick the point the divide.
	int mid = (left + right) / 2;
	merge_sort_helper(arr, left, mid);
	merge_sort_helper(arr, mid + 1, right);

	// We need another array to store the results.
	std::vector<int> result(right - left + 1);
	for (int i = left, j = mid + 1, first_unused = 0;
			i <= mid || j <= right; first_unused++)
	{
		if ((j > right) || (i <= mid && arr[i] <= arr[j]))
		{
			// `arr[i]` is better than `arr[j]`.
			result[first_unused] = arr[i];
			i++;
		}
		else
		{
			// `arr[i]` is worse than `arr[j]`.
			result[first_unused] = arr[j];
			j++;
		}
	}

	// Copy the result into the original array.
	for (int i = left; i <= right; i++)
		arr[i] = result[i - left];
}
