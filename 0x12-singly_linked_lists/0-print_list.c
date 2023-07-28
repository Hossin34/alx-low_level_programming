#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list
 * @s: singly linked list to print
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *s)
{
	size_t nodes = 0;

	while (s != NULL)
	{
		if (s->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", s->len, s->str);
		s = s->next;
		nodes++;
	}
	return (nodes);
}


