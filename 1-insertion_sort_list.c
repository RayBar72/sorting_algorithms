#include "sort.h"

/**
 * inserta - function that inser a node in position
 * @list: pointer to the double linked list
 * @actual: position to be compared
 */

static void inserta(listint_t **list, listint_t *actual)
{
	listint_t *prev = actual->prev;

	prev->next = actual->next;
	if (prev->prev)
		prev->prev->next = actual;
	actual->prev = prev->prev;
	prev->prev = actual;
	if (actual->next)
		actual->next->prev = prev;
	actual->next = prev;
	if (prev == *list)
		*list = actual;
}

/**
 * ad_locate - function compares and locates nodes for insertion
 * @list: pointer to the double linked list
 * @actual: position to be compared
 */

static void ad_locate(listint_t **list, listint_t *actual)
{
	int number = actual->n;

	while (actual->prev && number < actual->prev->n)
	{
		inserta(list, actual);
		print_list(*list);
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: pointer to pointer for the double linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *actual = NULL, *next = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	actual = (*list)->next;
	while (actual)
	{
		next = actual->next;
		ad_locate(list, actual);
		actual = next;
	}
}
