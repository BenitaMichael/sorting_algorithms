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
 * bubble_sort - Sort an array of integers in ascending order
 * @array: An array of integers to sort
 * @size: The size of the array
 * Description: Prints the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_function(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}

