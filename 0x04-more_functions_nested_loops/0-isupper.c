#include "main.h"

/**
* _isupper - checks if a char is uppercase
* @c: character to check
*
* Return: returns either 0 or 1
*/

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}
