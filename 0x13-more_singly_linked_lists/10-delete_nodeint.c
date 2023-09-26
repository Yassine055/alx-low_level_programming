#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index.
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to be deleted (starting from 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	listint_t *current = *head;
	listint_t *temp = NULL;
	unsigned int count = 0;

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (count < index - 1)
	{
		if (current->next == NULL)
			return (-1);  /* Index out of range. */
		current = current->next;
		count++;
	}

	if (current->next != NULL)
	{
		temp = current->next;
		current->next = temp->next;
		free(temp);
		return (1);
	}

	return (-1);  /* Index out of range. */
}
