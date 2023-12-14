#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursive helper function for advanced_binary
 * @array: Pointer to the first element of the array to search in
 * @low: The lower index of the current search range
 * @high: The higher index of the current search range
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
    if (low > high)
        return (-1);

    size_t mid = (low + high) / 2;

    printf("Searching in array: %d", array[low]);
    for (size_t i = low + 1; i <= mid; ++i)
        printf(", %d", array[i]);
    printf("\n");

    if (array[mid] == value)
    {
        if (mid == low || array[mid - 1] != value)
            return (mid);

        return advanced_binary_recursive(array, low, mid - 1, value);
    }

    if (array[mid] < value)
        return advanced_binary_recursive(array, mid + 1, high, value);

    return advanced_binary_recursive(array, low, mid - 1, value);
}

/**
 * advanced_binary - Searches for a value in a sorted array using Advanced Binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL)
        return (-1);

    return advanced_binary_recursive(array, 0, size - 1, value);
}
