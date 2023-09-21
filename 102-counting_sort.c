#include "sort.h"

/**
 * maximum_number - function to get the maximum value in an
 * array of integers
 * @array: An array of integers
 * @size: The size of the array
 * Return: returns the maximum integer in the array
 */
int maximum_number(int *array, int size)
{
	int a;
	int max_num;

	for (max_num = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max_num)
			max_num = array[a];
	}

	return (max_num);
}


/**
 * counting_sort -  function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 * Description: Prints the counting array after setting it up
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *count, *sorted;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = maximum_number(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}

