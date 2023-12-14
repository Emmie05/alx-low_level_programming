#include <stdio.h>
#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array using Exponential search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
    if (array == NULL)
        return (-1);

    if (array[0] == value)
    {
        printf("Value checked array[0] = [%d]\n", array[0]);
        return (0);
    }

    size_t bound = 1;

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    size_t low = bound / 2;
    size_t high = (bound < size - 1) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", low, high);

    while (low <= high)
    {
        size_t mid = (low + high) / 2;
        printf("Searching in array: %d", array[low]);

        for (size_t i = low + 1; i <= mid; ++i)
            printf(", %d", array[i]);

        printf("\n");

        if (array[mid] == value)
            return mid;

        if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (-1);
}
