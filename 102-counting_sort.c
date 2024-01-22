#include "sort.h"

/**
 * find_max - Finds the maximum value in an array
 * @array: The array to find the maximum value from
 * @size: Number of elements in @array
 * Return: The maximum value in the array
 */
int find_max(int *array, size_t size)
{
	int maxim = array[0];
	size_t x;

	for (x = 1; x < size; x++)
	{
		if (array[x] > maxim)
		{
			maxim = array[x];
		}
	}
	return (maxim);
}

/**
 * create_counting_array - Creates counting array
 * @max: The maximum value in the input array
 * Return: The counting array
 */
int *create_counting_array(int max)
{
	int *counting_array = (int *)malloc((max + 1) * sizeof(int));
	int x;

	if (counting_array == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	for (x = 0; x <= max; x++)
	{
		counting_array[x] = 0;
	}
	return (counting_array);
}

/**
 * print_counting_array - Prints the counting array
 * @counting_array: The counting array to be printed
 * @max: The maximum value in the input array
 */
void print_counting_array(int *counting_array, int max)
{
	int x;

	printf("Counting array: ");
	for (x = 0; x <= max; x++)
	{
		printf("%d ", counting_array[x]);
	}
	printf("\n");
}

/**
 * update_array - Updates the original array
 * @array: The original array to be updated
 * @counting_array: The counting array containing occurrences
 * @max: The maximum value in the input array
 */
void update_array(int *array, int *counting_array, int max)
{
	size_t index = 0;
	int x;

	for (x = 0; x <= max; x++)
	{
		while (counting_array[x] > 0)
		{
			array[index] = x;
			index++;
			counting_array[x]--;
		}
	}
}

/**
 * counting_sort - Sorts an array using Counting Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int max;
	int *counting_array;
	size_t x;

	if (size <= 1)
	{
		return;
	}
	max = find_max(array, size);
	counting_array = create_counting_array(max);
	for (x = 0; x < size; x++)
	{
		counting_array[array[x]]++;
	}
	print_counting_array(counting_array, max);
	update_array(array, counting_array, max);
	free(counting_array);
}
