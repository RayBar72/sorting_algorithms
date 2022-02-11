#include "sort.h"

/**
 * minimus - Finds the least value in array at a given point
 * @pointer: pointer to array
 * @counter: size not walked of the array
 */

static int *minimus(int *pointer, int counter)
{
	int *min = pointer++;

	while (--counter)
	{
		if (*pointer < *min)
			min = pointer;
		pointer++;
	}
	return (min);
}

/**
 * selection_sort - Sorts array using Selection sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int *pointer = NULL, *min = NULL, temp = 0;
	size_t counter = size;

	if (size < 2)
		return;
	pointer = array;
	while (counter > 1)
	{
		min = minimus(pointer, counter--);
		if (pointer != min)
		{
			temp = *min;
			*min = *pointer;
			*pointer = temp;
			print_array(array, size);
		}
		pointer++;
	}
}
