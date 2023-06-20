#include "main.h"

/**
 * _isalpha - check if an int is alpha
 *
 * @c: the int that being checked
 *
 * Return: 0 on success
 */

int _isalpha(int c)
{

	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}
