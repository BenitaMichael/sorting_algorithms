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
 * binary_heap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void binary_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		binary_heap(array, size, base, large);
	}
}

/**
 * heap_sort - function that sorts an array of integers in ascending
 * order using the Heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		binary_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		binary_heap(array, size, i, 0);
	}
}
