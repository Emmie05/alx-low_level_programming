#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number in which to clear the bit.
 * @index: The index of the bit to clear, starting from 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index >= sizeof(*n) * 8) // Check if the index is out of range
		return (-1);

	mask <<= index; // Move the 1 to the specified index

	mask = ~mask; // Invert the mask to have 0 at the desired bit position

	*n &= mask; // Clear the bit to 0 using bitwise AND operation

	return (1);
}
