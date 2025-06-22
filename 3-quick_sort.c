#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two elements
 * @a: pointer to first int
 * @b: pointer to second int
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: total size (for printing)
 *
 * Return: index of pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if ((i + 1) != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - recursive part of quick sort
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: full array size (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - main function to call quick sort
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
