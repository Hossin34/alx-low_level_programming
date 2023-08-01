#include "lists.h"

/**
 * free_listp2 - frees a linked list.
 * @head: head of a list.
 *
 * Return: void
 */
void free_listp2(listp_t **head)
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
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to head of list
 *
 * Return: number of nodes in the list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listp_t *lst, *new, *tmp;
	listint_t *lst;

	lst = NULL;
	while (*h != NULL)
	{
		new = malloc(sizeof(listp_t));

		if (new == NULL)
			exit(98);
		new->p = (void *)*h;
		new->next = lst;
		lst = new;
		tmp = lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (*h == tmp->p)
			{
				*h = NULL;
				free_listp2(&lst);
				return (count);
			}
		}
		lst = *h;
		*h = (*h)->next;
		free(lst);
		count++;
	}
	*h = NULL;
	free_listp2(&lst);
	return (count);
}

