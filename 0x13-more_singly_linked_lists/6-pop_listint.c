#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to pointer of first node of listint_t list
 * Return: head node's data (n)
 */
int pop_listint(listint_t **head)
{
	int count;
	listint_t *lst;
	listint_t *tmp;

	if (*head == NULL)
		return (0);

	tmp = *head;
	count = tmp->n;
	lst = tmp->next;
	free(tmp);
	*head = lst;
	return (count);
}

