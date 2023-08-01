#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets head to NULL
 * @head: pointer to pointer of first node of listint_t list
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;
	listint_t *lst;

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

