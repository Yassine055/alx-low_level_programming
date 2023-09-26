#include "lists.h"

/**
 * reverse_listint_recursive - Recursively reverses a listint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 * @prev: A pointer to the previous node.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint_recursive(listint_t **head, listint_t *prev)
{
	listint_t *next;

	if (*head == NULL)
		return (prev);

	next = (*head)->next;
	(*head)->next = prev;
	prev = *head;
	*head = next;

	return (reverse_listint_recursive(head, prev));
}

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (NULL);

	return (reverse_listint_recursive(head, NULL));
}
