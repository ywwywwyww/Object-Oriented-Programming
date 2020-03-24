/**
 * @file				bubble_sort.cpp
 * @author				Yan DAI
 * @date				Feb 26, 2020
 *
 * Implements bubble sort algorithm.
 */

#include "sorter.h"
#include <algorithm> // For `std::swap` function

/**
 * Implements bubble sort for class `Sorter`:
 *
 * Repeat the following process until the last element:
 * - For each element, compare each two adjacent elements after it.
 *   If the former one is bigger, swap it with the latter one.
 *
 * @param arr The array to be sorted.
 */
void Sorter::bubble_sort(std::vector<int> &arr)
{
	int len = arr.size(); // The length of the array

	for (int i = 0; i < len - 1; i++)
	{
		/**
		 * Here is a small trick to speed up bubble sort:
		 * In each run, if no exchange takes place,
		 * the whole array should be already sorted.
		 * So we can just `break` in this case.
		 */

		bool exchanged = false;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				exchanged = true;
			}
		}
		if (!exchanged)
			break;
	}
}
