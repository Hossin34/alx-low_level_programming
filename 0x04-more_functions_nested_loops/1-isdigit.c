#include "main.h"

/**
 * _isdigit - check if a char is digit
 *
 * @c: the char to check
 *
 * Return: either 0 or 1
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
