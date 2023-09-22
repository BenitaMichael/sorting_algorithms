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
 * bubble_sort - sorts an array
 * @array: array to be sorted
 * @size: array size
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swapped;

	if (size > 1)
	{
		do {
			swapped = 0;
			for (i = 0; i < size; i++)
			{
				if (array[i - 1] > array[i])
				{
					swap_function(&(array[i - 1]), &(array[i]));
					print_array(array, size);
					swapped = 1;
				}
			}
		} while (swapped == 1);
	}

}
