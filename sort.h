#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum bool - Representation of Boolean values
 * @false: Equals (0)
 * @true: Equals (1)
 */
typedef enum bool
{
	false = 0,
	true
} bool;


/**
 * struct listint_s - Doubly linked list node
 * @n: Integer in node
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



/* Given printing functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Swapping function */
void swap_function(int *a, int *b);


/* Sorting algoritms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif