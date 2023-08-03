#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if:
 * - The string contains a character other than '0' or '1'.
 * - The input string is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (; *b; b++)
	{
		if (*b == '0' || *b == '1')
		{
			result <<= 1; /* Shift result left by 1 to make space for the next bit */
			result += (*b - '0'); /* Add the new bit to the result */
		}
		else
		{
			return (0); /* Invalid character encountered, return 0 */
		}
	}

	return (result);
}
