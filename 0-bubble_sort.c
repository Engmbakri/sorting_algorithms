#include <sort.h>

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
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				printf("Swap: ");
				for (size_t k = 0; k < size; k++)
				{
					printf("%d ", array[k]);
				}
				printf("\n");
			}
		}
	}
}
