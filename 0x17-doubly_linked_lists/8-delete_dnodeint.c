#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes node at index of a linked list.
 * @head: Double pointer to the head of the list.
 * @index: Index of the node to be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current != NULL)
	{
		if (i == index)
		{
			if (current->prev != NULL)
				current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			free(current);
			return (1);
		}
		current = current->next;
		i++;
	}

	return (-1);
}

