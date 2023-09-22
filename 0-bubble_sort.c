#include "sort.h"

/**
 * swap - swaps two array elements
 * @a: first element
 * @b: second element
 * Return: void
*/
void swap(int *a, int *b)
{
	int temp1, temp2;

	temp1 = *a;
	temp2 = *b;
	*a = temp2;
	*b = temp1;
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
					swap(&(array[i - 1]), &(array[i]));
					print_array(array, size);
					swapped = 1;
				}
			}
		} while (swapped == 1);
	}

}
