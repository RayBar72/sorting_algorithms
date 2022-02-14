#include "sort.h"

/**
 * knuth - gets largest Knuth seq
 * @size: size of array
 * Retur: the gap
 */
static size_t knuth(size_t size)
{
	size_t num = 1;

	while (num < size)
		num = num * 3 + 1;
	return ((num - 1) / 3);
}

/**
 * shell_sort - function that implements shell sorting
 * @array: array
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, g = 0;
	int x;

	if (size < 2)
		return;

	for (g = knuth(size); g; g = (g - 1) / 3)
	{
		for (i = g; i < size; i++)
		{
			x = array[i];
			for (j = i; j > g - 1 && array[j - g] > x; j -= g)
				array[j] = array[j - g];
			array[j] = x;
		}
		print_array(array, size);
	}
}
