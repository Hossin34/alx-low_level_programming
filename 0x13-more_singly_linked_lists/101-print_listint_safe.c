#include "lists.h"

/**
 * free_listp - frees a listp_t linked list.
 * @head: pointer to head of list
 *
 * Return: void
 */
void free_listp(listp_t **head)
{
	listp_t *tmp;
	listp_t *lst;

	if (head != NULL)
	{
		lst = *head;
		while ((tmp = lst) != NULL)
		{
			lst = lst->next;
			free(tmp);
		}
		*head = NULL;
	}
}

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to head of list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	listp_t *lst, *new, *tmp;

	lst = NULL;
	while (head != NULL)
	{
		new = malloc(sizeof(listp_t));

		if (new == NULL)
			exit(98);
		new->p = (void *)head;
		new->next = lst;
		lst = new;
		tmp = lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (head == tmp->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(&lst);
				return (count);
			}
		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		count++;
	}

	free_listp(&lst);
	return (count);
}

