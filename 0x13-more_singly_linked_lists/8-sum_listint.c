#include "lists.h"

/**
 * sum_listint - Computes the sum of n values in a listint_t list.
 * @head: Pointer to the list's head.
 *
 * Return: Sum of n values, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
	sum += current->n;
	current = current->next;
	}

	return (sum);
}
