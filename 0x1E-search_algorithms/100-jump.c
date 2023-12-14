#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using Jump search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
    if (array == NULL)
        return (-1);

    size_t jump = sqrt(size);
    size_t prev = 0;

    while (array[prev] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

        if (prev + jump >= size)
            break;

        if (array[prev + jump] >= value)
        {
            printf("Value found between indexes [%lu] and [%lu]\n", prev, prev + jump);
            break;
        }

        prev += jump;
    }

    for (size_t i = prev; i <= prev + jump && i < size; ++i)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);

        if (array[i] == value)
            return (i);
    }

    return (-1);
}
