#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int b_ui;
	int count, b2;

	if (!b)
		return (0);
	b_ui = 0;
	for (count = 0; b[count] != '\0'; count++)
		;
	for (count--, b2 = 1; count >= 0; count--, b2 *= 2)
	{
		if (b[count] != '0' && b[count] != '1')
			return (0);
		if (b[count] & 1)
			b_ui += b2;
	}

	return (b_ui);
}

