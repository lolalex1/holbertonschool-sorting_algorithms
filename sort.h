#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - doubly linked list node
 * @n: integer stored in the node
 * @prev: pointer to previous node
 * @next: pointer to next node
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Provided functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b, int *did_swap);

#endif /* SORT_H */
