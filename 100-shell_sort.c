#include "sort.h"

/**
 * shell_sort - Sorts an array using Shell sort algorithm
 * @array: array to be sorted
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t gape, x, y, z;
	int temporary;

	if (array == NULL || size < 2)
		return;
	gape = 1;
	while (gape < size / 3)
		gape = gape * 3 + 1;
	while (gape > 0)
	{
		for (x = gape; x < size; x++)
		{
			temporary = array[x];
			for (y = x; y >= gape && array[y - gape] > temporary; y -= gape)
			{
				array[y] = array[y - gape];
			}
			array[y] = temporary;
		}
		gape = (gape - 1) / 3;
		for (z = 0; z < size - 1; z++)
			printf("%d, ", array[z]);
		printf("%d\n", array[size - 1]);
	}
}
