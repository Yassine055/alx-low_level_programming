#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;

	while (current)
	{
	printf("[%p] %d\n", (void *)current, current->n);

	current = current->next;
	count++;

	if (current && current->next >= current)
		{
		printf("-> [%p] %d\n", (void *)current, current->n);
		exit(98); /* Exit with status 98 if a loop is detected */
		}
	}

	return (count);
}
