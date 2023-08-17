#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index.
 * @head: Double pointer to the head of the list.
 * @index: Index of the node that should be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL)
    {
        return (-1);  // Empty list, deletion failed
    }

    dlistint_t *current = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(current);
        return (1);
    }

    unsigned int count = 0;

    while (current != NULL && count < index)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        return (-1);  // Cannot delete the node at the specified index
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }

    free(current);
    return (1);
}
