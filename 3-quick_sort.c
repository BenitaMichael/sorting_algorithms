#include "sort.h"

int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);

/**
 * lomuto_partition - function used to perform the Lomuto partition scheme
 * on a subset of an array of integers
 * @size: size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *partitionElement, top, down;

	partitionElement = array + right;
	for (top = down = left; down < right; down++)
	{
		if (array[down] < *partitionElement)
		{
			if (top < down)
			{
				swap_function(array + down, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *partitionElement)
	{
		swap_function(array + top, partitionElement);
		print_array(array, size);
	}

	return (top);
}


/**
 * lomuto_sort -  function is an implementation of the quicksort
 * algorithm using recursion and the Lomuto partition scheme
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int ele;

	if (right - left > 0)
	{
		ele = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, ele - 1);
		lomuto_sort(array, size, ele + 1, right);
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

	lomuto_sort(array, size, 0, size - 1);
}
