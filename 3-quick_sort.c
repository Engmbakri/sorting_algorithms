#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1);
}

/**
 * quick_sort_recursive - Recursively sorts array
 *
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high);
		print_array(array, high - low + 1);
		quick_sort_recursive(array, low, pivot_index - 1);
		quick_sort_recursive(array, pivot_index + 1, high);
	}
}

/**
 * lomuto_partition - Performs the Lomuto partition for Quick sort
 *
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * Return: The final pivot index
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot, i, temp;

	pivot = array[high];
	i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	return (i + 1);
}
