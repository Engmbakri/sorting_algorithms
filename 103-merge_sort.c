#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_merge_step - Prints a step in the merging process
 * @array: The array to be printed
 * @size: Number of elements in the array
 */
void print_merge_step(int *array, size_t size)
{
	size_t x;

	printf("[Done]: ");
	for (x = 0; x < size; x++)
	{
		if (x > 0)
			printf(", ");
		printf("%d", array[x]);
	}
	printf("\n");
}

/**
 * merge - Merges two sub-arrays into a sorted array
 * @array: The original array
 * @left: Pointer to the left sub-array
 * @left_size: Size of the left sub-array
 * @right: Pointer to the right sub-array
 * @right_size: Size of the right sub-array
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((left_size + right_size) * sizeof(int));

	printf("[Done]: ");
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			temp[k] = left[i];
			i++;
		}
		else
		{
			temp[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		temp[k] = left[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		temp[k] = right[j];
		j++;
		k++;
	}
	for (i = 0; i < left_size + right_size; i++)
		array[i] = temp[i];
	print_array(array, left_size + right_size);
	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left = array;
	int *right;

	if (size > 1)
	{
		mid = size / 2;
		right = array + mid;
		printf("Merging...\n[left]: ");
		print_array(left, mid);
		printf("[right]: ");
		print_array(right, size - mid);
		merge_sort(left, mid);
		merge_sort(right, size - mid);
		merge(array, left, mid, right, size - mid);
	}
}
