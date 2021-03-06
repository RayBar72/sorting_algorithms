#include "sort.h"

/**
 * choco_cambio - function that calls recursive
 * @array: an array
 * @size: size of the array
 * @inic: Begins partition
 * @fin: Ends partition
 */
static void choco_cambio(int *array, ssize_t inic, ssize_t fin, ssize_t size)
{
	int x;

	if (inic != fin)
	{
		x = array[inic];
		array[inic] = array[fin];
		array[fin] = x;
		print_array(array, size);
	}
}

/**
 * partition - function that calls recursive
 * @array: an array
 * @size: size of the array
 * @inic: Begins partition
 * @fin: Ends partition
 * Return: int
 */
static size_t partition(int *array, ssize_t inic, ssize_t fin, ssize_t size)
{
	int x = array[fin];
	ssize_t y = 0, z = inic;

	for (y = inic; y <= fin; y++)
		if (array[y] < x)
		{
			choco_cambio(array, z, y, size);
			z++;
		}
	choco_cambio(array, z, fin, size);
	return (z);
}


/**
 * choco_quick - function that calls recursive
 * @array: an array
 * @size: size of the array
 * @inic: Begins partition
 * @fin: Ends partition
 */

static void choco_quick(int *array, ssize_t inic, ssize_t fin, ssize_t size)
{
	ssize_t part;

	if (inic < fin)
	{
		part = partition(array, inic, fin, size);
		choco_quick(array, inic, part - 1, size);
		choco_quick(array, part + 1, fin, size);
	}
}


/**
 * quick_sort - function that sorts with quick algorithm
 * @array: an array
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	choco_quick(array, 0, size - 1, size);
}
