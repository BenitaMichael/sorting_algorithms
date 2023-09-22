#include "sort.h"

int maximum_number(int *array, int size);
void counting_sorting(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * maximum_number - function to get the maximum value in an
 * array of integers
 * @array: An array of integers
 * @size: The size of the array
 * Return: returns the maximum integer in the array
 */
int maximum_number(int *array, int size)
{
	int max_num, a;

	for (max_num = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max_num)
			max_num = array[a];
	}

	return (max_num);
}

/**
 * counting_sorting - Sort the significant digits of an array of integers
 * in ascending order using counting algo.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void counting_sorting(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = maximum_number(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		counting_sorting(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
