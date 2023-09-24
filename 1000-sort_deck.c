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
 * @card: Pointer to deck_node_t
 *
 * Return: the  number value of cards
 */

char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}


/**
 * inserting_sort_deck_value - The function that sorts the deck of cards
 *  from spades to diamonds from ace to king.
 *
 * @deck:  Pointer to address deck_node_t doubly-linked list
 */
void inserting_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *rep, *shove, *tmp;

	for (rep = (*deck)->next; rep != NULL; rep = tmp)
	{
		tmp = rep->next;
		shove = rep->prev;
		while (shove != NULL &&
		       shove->card->kind == rep->card->kind &&
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
void inserting_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *rep, *shove, *tmp;

	for (rep = (*deck)->next; rep != NULL; rep = tmp)
	{
		tmp = rep->next;
		shove = rep->prev;
		while (shove != NULL && shove->card->kind > rep->card->kind)
		{
			shove->next = rep->next;
			if (rep->next != NULL)
				rep->next->prev = shove;
			rep->prev = shove->prev;
			rep->next = shove;
			if (shove->prev != NULL)
				shove->prev->next = rep;
			else
				*deck = rep 
