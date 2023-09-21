#include "sort.h"

/**
 * node_swap - Swap nodes in a listint_t doubly-linked list
 * @h: A pointer to the head of the doubly-linked list
 * @n1: A pointer to the first node
 * @n2: Pointer to the second node
 */
void node_swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order
 * using the Insertion sort algorithm
 * @list: ointer to the head of a doubly-linked list
 * Description: prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter;
	listint_t *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			node_swap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

