#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *a, int *b);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high);
int lomuto_partition(int *array, int low, int high);
void shell_sort(int *array, size_t size);
int find_max(int *array, size_t size);
int *create_counting_array(int max);
void print_counting_array(int *counting_array, int max);
void update_array(int *array, int *counting_array, int max);
void counting_sort(int *array, size_t size);
void print_merge_step(int *array, size_t size);
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size);
void merge_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t root);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
