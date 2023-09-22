#include "sort.h"

void swap_function(int *a, int *b);
int partition(int *array, size_t size, int left, int right);
void sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);


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
 * partition - function used to perform the Lomuto partition scheme
 * on a subset of an array of integers
 * @array: represents the array
 * @size: size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
 * Return: The final partition index
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, top, bottom;

	pivot = array + right;
	for (top = bottom = left; bottom < right; bottom++)
	{
		if (array[bottom] < *pivot)
		{
			if (top < bottom)
			{
				swap_function(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_function(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * sort -  function is an implementation of the quicksort
 * algorithm using recursion and the Lomuto partition scheme
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 * Description: Uses the Lomuto partition scheme
 */
void sort(int *array, size_t size, int left, int right)
{
	int a;

	if (right - left > 0)
	{
		a = partition(array, size, left, right);
		sort(array, size, left, a - 1);
		sort(array, size, a + 1, right);
	}
}


/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 * Description: Uses the Lomuto partition scheme
 * Prints the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
