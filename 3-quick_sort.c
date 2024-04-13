#include "sort.h"

/**
  * quick_sort - Sorts an array of integers in ascending order
  * using the Quick Sort algorithm.
  * @array: Pointer to the first element of the array to be sorted.
  * @size: Number of elements in the array.
  *
  */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
  * quick_sort_rec - Recursively sorts a subarray of integers in
  * ascending order.
  * using the Quick Sort algorithm.
  * @array: Pointer to the first element of the array to be sorted.
  * @lo: Index of the lower bound of the subarray.
  * @hi: Index of the higher bound of the subarray.
  * @size: Number of elements in the array.
  *
  */
void quick_sort_rec(int *array, int lo, int hi, size_t size)
{
	int left_p = 0;

	if (lo < hi)
	{
		left_p = lomuto_partition(array, lo, hi, size);
		quick_sort_rec(array, lo, left_p - 1, size);
		quick_sort_rec(array, left_p + 1, hi, size);
	}
}

/**
  * lomuto_partition - Partitions a subarray using the Lomuto partition scheme.
  * @array: Pointer to the first element of the array to be partitioned.
  * @lo: Index of the lower bound of the subarray.
  * @hi: Index of the higher bound of the subarray.
  * @size: Number of elements in the array.
  *
  * Return: Index of the pivot element after partitioning.
  */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int idx_i = 0, idx_j = 0, pivot = 0, tmp = 0;

	pivot = array[hi];
	idx_i = lo;

	for (idx_j = lo; idx_j < hi; ++idx_j)
	{
		if (array[idx_j] < pivot)
		{
			tmp = array[idx_i];
			array[idx_i] = array[idx_j];
			array[idx_j] = tmp;

			if (tmp != array[idx_i])
				print_array(array, size);

			++idx_i;
		}
	}

	tmp = array[idx_i];
	array[idx_i] = array[hi];
	array[hi] = tmp;

	if (tmp != array[idx_i])
		print_array(array, size);

	return (idx_i);
}
