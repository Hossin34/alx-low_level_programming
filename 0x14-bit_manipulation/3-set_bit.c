#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the number to be modified
 * @index: index of the bit to be set to 1
 *
 * Return: 1 if it worked, or -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int set;

	if (index > 63)
		return (-1);
	set = 1 << index;
	*n = (*n | set);
	return (1);
}

