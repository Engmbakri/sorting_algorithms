#include "sort.h"

/**
 * swap - function to swap array element
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
 * bubble_sort - fuction sort the array using Bubble sort algorithm
 * @array: pointer to array
 * @size: array size
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
