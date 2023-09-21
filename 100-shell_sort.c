#include "sort.h"

/**
 * swap_function - function to swap two integers in an
 * array using a temp storage
 * @a: The first integer
 * @b: The second integer
 */
void swap_function(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: Array of integers
 * @size: Size of the array
 * Description: Uses the Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
				swap_function(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}

