#include "sort.h"

/**
 * bubble_sort- Function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @array: Pointer to array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0;
	int control = 1;

	if (size < 2)
		return;
	while (control)
	{
		control = 0;
		for (i = 0; i < size - 1; i++)
			if (array[i] > array[i + 1])
			{
				array[i] = array[i] + array[i + 1];
				array[i + 1] = array[i] - array[i + 1];
				array[i] = array[i] - array[i + 1];
				print_array(array, size);
				control = 1;
			}
	}
}
