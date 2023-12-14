#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers using Jump search
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where the value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    if (list == NULL)
        return (NULL);

    size_t jump_step = sqrt(size);
    listint_t *current = list, *prev = NULL;

    while (current != NULL && current->n < value)
    {
        prev = current;
        for (size_t i = 0; i < jump_step && current->next != NULL; ++i)
            current = current->next;

        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);

    while (prev != NULL && prev->index <= current->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);

        prev = prev->next;
    }

    return (NULL);
}
