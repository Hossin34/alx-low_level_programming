#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to head of list
 *
 * Return: address of node where loop starts or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *lst;
	listint_t *tmp;

	lst = head;
	tmp = head;
	while (head && lst && lst->next)
	{
		head = head->next;
		lst = lst->next->next;
		if (head == lst)
		{
			head = tmp;
			tmp =  lst;
			while (1)
			{
				lst = tmp;
				while (lst->next != head && lst->next != tmp)
					lst = lst->next;
				if (lst->next == head)
					break;
				head = head->next;
			}
			return (lst->next);
		}
	}
	return (NULL);
}

