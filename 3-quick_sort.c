#include "sort.h"

/**
 * swap - swap two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b, int *did_swap)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		*did_swap = 1;
	}
}

/**
 * lomuto_partition - partition array using Lomuto scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: total array size (for print_array)
 *
 * Return: final pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, did_swap;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			did_swap = 0;
			swap(&array[i], &array[j], &did_swap);
			if (did_swap)
				print_array(array, size);
		}
	}
	did_swap = 0;
	swap(&array[i + 1], &array[high], &did_swap);
	if (did_swap)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - recursive quick sort helper
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for print_array)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sort array using quick sort (Lomuto partition)
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
