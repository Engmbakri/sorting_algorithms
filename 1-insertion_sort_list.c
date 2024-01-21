#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;

	while (current != NULL)
	{
		key = current;

		while (key->prev != NULL && key->n < key->prev->n)
		{
			if (key->next != NULL)
				key->next->prev = key->prev;
			key->prev->next = key->next;

			key->next = key->prev;
			key->prev = key->prev->prev;
			if (key->prev != NULL)
				key->prev->next = key;
			if (key->next->prev == NULL)
				*list = key;
			key->next->prev = key;
			print_list(*list);
		}
		current = current->next;
	}
}
