#include "sort.h"

/**
 * swap_nodes - swap two nodes in a doubly linked list
 * @a: first node
 * @b: second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	b->next = a;
	a->prev = b;

	print_list(*list);
}

/**
 * insertion_sort_list - sort a doubly linked list using insertion sort
 * @list: pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		while (prev && current->n < prev->n)
		{
			swap_nodes(list, prev, current);
			prev = current->prev;
		}
		current = current->next;
	}
}
