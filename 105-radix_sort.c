#include "sort.h"
#include <stdlib.h>

/**
 * find_max - Get the maximum value in an array
 * @array: The array
 * @size: Size of the array
 * Return: The maximum value
 */
int find_max(int *array, size_t size)
{
	int the_max = array[0];
	size_t x;

	for (x = 1; x < size; x++)
	{
		if (array[x] > the_max)
			the_max = array[x];
	}
	return (the_max);
}

/**
 * counting_sort - Sort array using counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The exponent
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output, *counting, x;
	int the_max = 10;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	counting = malloc(sizeof(int) * the_max);
	if (!counting)
	{
		free(output);
		return;
	}
	for (x = 0; x < the_max; x++)
		counting[x] = 0;
	for (x = 0; x < (int)size; x++)
		counting[(array[x] / exp) % 10]++;
	for (x = 1; x < the_max; x++)
		counting[x] += counting[x - 1];
	for (x = size - 1; x >= 0; x--)
	{
		output[counting[(array[x] / exp) % 10] - 1] = array[x];
		counting[(array[x] / exp) % 10]--;
	}
	for (x = 0; x < (int)size; x++)
		array[x] = output[x];
	free(output);
	free(counting);
}

/**
 * radix_sort - Sort an array using Radix sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int the_max, ex;

	if (size < 2 || !array)
		return;
	the_max = find_max(array, size);
	for (ex = 1; the_max / ex > 0; ex *= 10)
	{
		counting_sort(array, size, ex);
		print_array(array, size);
	}
}

