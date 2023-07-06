#include "main.h"

/**
 * binary_to_uint - Converts a binary number represented as a string to an
 *                  unsigned integer.
 * @b: A string containing the binary number.
 *
 * Description: This function takes a string of characters that represents
 * a binary number and converts it to an unsigned integer. If the input string
 * is null or contains any characters other than '0' or '1', the function
 * returns 0. Otherwise, the function performs the binary to decimal conversion
 * by iterating over each character of the string from left to right. It starts
 * with a decimal value of 0 and for each bit, it multiplies current decimal
 * value by 2 and adds the value of the current bit (0 or 1). The resulting
 * decimal value is returned as an unsigned integer.
 *
 * Return: The converted unsigned integer or 0 if the input string is invalid.
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int decimal_value = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0)
		decimal_value = 2 * decimal_value + (b[i] - '0');
	}

	return (decimal_value);
}
