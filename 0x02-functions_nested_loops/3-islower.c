#include "main.h"

/**
 *_islower - check for a lowercase char
 *@c: char that being checked
 * Return:  0 on success
 */

int _islower(int c)
{

	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
