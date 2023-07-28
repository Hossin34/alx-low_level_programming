#include "lists.h"
#include <stdio.h>

/**
 * list_len - returns the number of elements in a linked list_t list
 * @s: singly linked list to count the number of elements
 *
 * Return: the number of elements in a linked list_t list
 */
size_t list_len(const list_t *s)
{
	size_t nodes;

	for (nodes = 0 ; s != NULL ; nodes++)
		s = s->next;
	return (nodes);
}

