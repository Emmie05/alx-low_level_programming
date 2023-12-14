#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: Pointer to the first node where the value is located, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    if (list == NULL)
        return (NULL);

    skiplist_t *express = list;

    while (express->express != NULL && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        list = express;
        express = express->express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", list->index, express->index);

    while (list != NULL && list->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
        list = list->next;
    }

    if (list != NULL)
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);

    if (list != NULL && list->n == value)
        return (list);

    return (NULL);
}
