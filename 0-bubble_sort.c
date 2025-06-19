#include "sort.h"
/**
 * bubble_sort - sorts an array of integers using Bubble sort
 * @array: the array to sort
 * @size: the array size
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, flag;

	for (i = 0; i <= size - 1; i++)
	{
		flag = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
