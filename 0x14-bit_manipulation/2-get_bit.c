#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number from which to extract the bit.
 * @index: The index of the bit to get, starting from 0.
 *
 * Return: The value of the bit at index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index >= sizeof(n) * 8) // Check if the index is out of range
		return (-1);

	mask <<= index; // Move the 1 to the specified index

	if (n & mask) // Check if the bit is set
		return (1);
	else
		return (0);
}
