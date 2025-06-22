#include "sort.h"

/**
 * swap - Swap two integers if they are not equal
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array
 * @low: Starting index
 * @high: Ending index (pivot index)
 * @size: Array size (for print_array)
 * Return: Index of pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j && array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			else if (i != j)
			{
				swap(&array[i], &array[j]);
			}
		}
	}
	if ((i + 1) != high && array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	else if ((i + 1) != high)
	{
		swap(&array[i + 1], &array[high]);
	}
	return (i + 1);
}

/**
 * quick_sort_rec - Recursive quick sort
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sort_rec(array, low, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Quick sort entry point
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
