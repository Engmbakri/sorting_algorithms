#include "sort.h"

/**
 * swap - function to swap array items
 * @a: int element
 * @b: int element
 * Return: void
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - function implements the Bubble Sort algorithm
 * @array: pointert to array
 * @size: array size
*/

void bubble_sort(int *array, size_t size)
{
	size_t x;
	size_t y;
	size_t z;

	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				swap(&array[y], &array[y + 1]);
				printf("Swap: ");
				for (z = 0; z < size; z++)
				{
					printf("%d ", array[z]);
				}
				printf("\n");
			}
		}
	}
}
