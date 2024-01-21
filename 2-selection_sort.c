#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, d, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		min_index = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min_index])
				min_index = y;
		}
		if (min_index != x)
		{
			temp = array[x];
			array[x] = array[min_index];
			array[min_index] = temp;
			for (d = 0; d < size - 1; d++)
				printf("%d, ", array[d]);
			printf("%d\n", array[size - 1]);
		}
	}
}
