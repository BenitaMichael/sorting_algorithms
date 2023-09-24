#include "deck.h"

int _strcmp(const void *a, const void *b);
char get_value(deck_node_t *card);
void inserting_sort_deck_use(deck_node_t **deck);
void inserting_sort_deck_type(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - function that compares cards to be sorted
 * @value1: The first string input to be compared
 * @value2: The second string input to be compared
 * Return: Positive byte difference if value1 >value2 or (0) if
 * (value1 == value2) or Negative byte difference if value1 < value2
 */

int _strcmp(const char *value1, const char *value2)
{
	while (*value1 && *value2 && *value1 == *value2)
	{
		value1++;
		value2++;
	}

	if (*value1 != *value2)
		return (*value1 - *value2);
	return (0);
}

/**
 * get_value - Fucnction that gets the number
 * value of cards
 *
 * @cards: Pointer to deck_node_t
 *
 * Return: the  number value of cards
 */

char get_value(deck_node_t *cards)
{
	if (_strcmp(cards->cards->value, "Ace") == 0)
		return (0);
	if (_strcmp(cards->cards->value, "1") == 0)
		return (1);
	if (_strcmp(cards->cards->value, "2") == 0)
		return (2);
	if (_strcmp(cards->cards->value, "3") == 0)
		return (3);
	if (_strcmp(cards->cards->value, "4") == 0)
		return (4);
	if (_strcmp(cards->cards->value, "5") == 0)
		return (5);
	if (_strcmp(cards->cards->value, "6") == 0)
		return (6);
	if (_strcmp(cards->cards->value, "7") == 0)
		return (7);
	if (_strcmp(cards->cards->value, "8") == 0)
		return (8);
	if (_strcmp(cards->cards->value, "9") == 0)
		return (9);
	if (_strcmp(cards->cards->value, "10") == 0)
		return (10);
	if (_strcmp(cards->cards->value, "Jack") == 0)
		return (11);
	if (_strcmp(cards->cards->value, "Queen") == 0)
		return (12);
	return (13);
}


/**
 * inserting_sort_deck_use - The function that sorts the deck of cards
 *  from spades to diamonds from ace to king.
 *
 * @deck:  Pointer to address deck_node_t doubly-linked list
 */
void inserting_sort_deck_use(deck_node_t **deck)
{
	deck_node_t *rep, *shove, *tmp;

	for (rep = (*deck)->next; rep != NULL; rep = tmp)
	{
		tmp = rep->next;
		shove = rep->prev;
		while (shove != NULL &&
		       shove->cards->type == rep->cards->type &&
		       get_value(shove) > get_value(rep))
		{
			shove->next = rep->next;
			if (rep->next != NULL)
				rep->next->prev = shove;
			rep->prev = shove->prev;
			rep->next = shove;
			if (shove->prev != NULL)
				shove->prev->next = rep;
			else
				*deck = rep;
			shove->prev = rep;
			shove = rep->prev;
		}
	}
}


/**
 * inserting_sort_deck_type - Function that sorts the deck of cards
 *
 * @deck:  Pointer to address deck_node_t doubly-linked list
 */
void inserting_sort_deck_type(deck_node_t **deck)
{
	deck_node_t *rep, *shove, *tmp;

	for (rep = (*deck)->next; rep != NULL; rep = tmp)
	{
		tmp = rep->next;
		shove = rep->prev;
		while (shove != NULL && shove->cards->type > rep->cards->type)
		{
			shove->next = rep->next;
			if (rep->next != NULL)
				rep->next->prev = shove;
			rep->prev = shove->prev;
			rep->next = shove;
			if (shove->prev != NULL)
				shove->prev->next = rep;
			else
				*deck = rep;
			shove->prev = rep;
			shove = rep->prev;
		}
	}
}


/**
 * sort_deck - function that sorts a deck of cards
 *
 * @deck: Pointer to address deck_node_t doubly-linked list
 */

void sort_deck(deck_node_t **deck)
{
	
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)

	inserting_sort_deck_use(deck);
	inserting_sort_deck_type(deck);
}
