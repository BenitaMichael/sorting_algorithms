#include "deck.h"

/**
 * compare_cards - function that compares cards to be sorted
 * @a: The first string input to be compared
 * @b: The second string input to be compared
 * Return: Positive byte difference if value1 >value2 or (0) if
 * (value1 == value2) or Negative byte difference if value1 < value2
 */

int compare_cards(const void *a, const void *b)
{
	int value1, value2;

	const card_t *card1 = (*(const deck_node_t **)a)->card;
	const card_t *card2 = (*(const deck_node_t **)b)->card;

	if (card1->kind < card2->kind)
		return (-1);
	else if (card1->kind > card2->kind)
		return (1);

		if (strcmp(card1->value, "Ace") == 0)
			value1 = 1;
		else if (strcmp(card1->value, "Jack") == 0)
			value1 = 11;
		else if (strcmp(card1->value, "Queen") == 0)
			value1 = 12;
		else if (strcmp(card1->value, "King") == 0)
			value1 = 13;
		else
			value1 = atoi(card1->value);

		if (strcmp(card2->value, "Ace") == 0)
			value2 = 1;
		else if (strcmp(card2->value, "Jack") == 0)
			value2 = 11;
		else if (strcmp(card2->value, "Queen") == 0)
			value2 = 12;
		else if (strcmp(card2->value, "King") == 0)
			value2 = 13;
		else
			value2 = atoi(card2->value);

		if (value1 < value2)
			return (-1);
		else if (value1 > value2)
			return (1);
		else
			return (0);
}

/**
 * sort_deck - function that sorts a deck of cards
 * @deck: Pointer to address deck_node_t doubly-linked list
 * Return: returns nothing (void)
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

