#include "deck.h"

int _strcmp(const void *a, const void *b);
char get_value(deck_node_t *card);
void sort_deck(deck_node_t **deck);
void insert_sort_deck_kind(deck_node_t **deck);
void insert_sort_deck_value(deck_node_t **deck);


/**
 * _strcmp - function that compares cards to be sorted
 * @value1: The first string input to be compared
 * @value2: The second string input to be compared
 * Return: Positive byte difference if value1 >value2 or (0) if
 * (value1 == value2) or Negative byte difference if value1 < value2
 */

int _strcmp(const char *value1, const void *value2)
{
	while (*value1 && *value2 && *value1 == *value2)
	{
		++value1;
		++value2;
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
 * Return: return the  number value of cards
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
 * sort_deck - function that sorts a deck of cards
 *
 * @deck: Pointer to address deck_node_t doubly-linked list
 */

void sort_deck(deck_node_t **deck)
{
	int i = 0;

	deck_node_t *node = *deck;
	deck_node_t *deck_array[52];

	while (node != NULL)
	{
		deck_array[i++] = node;
		node = node->next;
	}

	qsort(deck_array, 52, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < 51; i++)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}
	deck_array[0]->prev = NULL;
	deck_array[51]->next = NULL;
	*deck = deck_array[0];
}
