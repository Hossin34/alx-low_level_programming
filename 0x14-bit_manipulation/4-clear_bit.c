#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the number to be modified
 * @index: index of the bit to be set to 0
 *
 * Return: 1 if it worked, or -1 if an error occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int clear;

	if (index > 63)
		return (-1);
	clear = 1 << index;
	if (*n & clear)
		*n ^= clear;
	return (1);
}

