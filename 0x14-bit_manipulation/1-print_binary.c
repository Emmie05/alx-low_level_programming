#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted and printed.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int size = sizeof(n) * 8; // Number of bits in an unsigned long int

	mask <<= (size - 1); // Move the 1 to the leftmost bit

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask)
	{
		if (n & mask) // Check if the bit is set
			_putchar('1');
		else
			_putchar('0');

		mask >>= 1; // Move the mask to the right
	}
}
