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
 * selection_sort -  function that sorts an array of integers in
 * ascending order
 * using the Selection sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 * Description: prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min = array + a;
		for (b = a + 1; b < size; b++)
			min = (array[b] < *min) ? (array + b) : min;

		if ((array + a) != min)
		{
			swap_function(array + a, min);
			print_array(array, size);
		}
	}
}
