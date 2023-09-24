#include "deck.h"

int _strcmp(const char *a, const char *b);
char get_value(deck_node_t *card);
void inserting_sort_deck_value(deck_node_t **deck);
void inserting_sort_deck_kind(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - function that compares cards to be sorted
 *
 * @a: The first string input to be compared
 *
 * @b: The second string input to be compared
 *
 * Return: Positive byte difference if a >b or (0) if
 * (a == b) or Negative byte difference if a < b
 */

int _strcmp(const char *a, const char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}

	if (*a != *b)
		return (*a - *b);
	return (0);
}

/**
 * get_value - Fucnction that gets the number
 * value of cards
 *
 * @card: Pointer to deck_node_
