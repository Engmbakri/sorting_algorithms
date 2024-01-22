#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temporary = *a;
	*a = *b;
	*b = temporary;
}

/**
 * heapify - Maintains the max heap
 * @array: The array representing the heap
 * @size: The size of the array
 * @root: The index of the current root of the subtree
 */
void heapify(int *array, size_t size, size_t root)
{
	size_t large = root;
	size_t leftside = 2 * root + 1;
	size_t rightside = 2 * root + 2;

	if (leftside < size && array[leftside] > array[large])
		large = leftside;
	if (rightside < size && array[rightside] > array[large])
		large = rightside;
	if (large != root)
	{
		swap(&array[root], &array[large]);
		print_array(array, size);
		heapify(array, size, large);
	}
}

/**
 * heap_sort - Sorts an array using Heap Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t x;

	for (x = size / 2; x > 0; x--)
		heapify(array, size, x - 1);
	for (x = size - 1; x > 0; x--)
	{
		swap(&array[0], &array[x]);
		print_array(array, size);
		heapify(array, x, 0);
	}
}
