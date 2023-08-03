#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the number in which to set the bit.
 * @index: The index of the bit to set, starting from 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index >= sizeof(*n) * 8) // Check if the index is out of range
		return (-1);

	mask <<= index; // Move the 1 to the specified index

	*n |= mask; // Set the bit to 1 using bitwise OR operation

	return (1);
}
