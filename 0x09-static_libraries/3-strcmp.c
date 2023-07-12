#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: negative if s1 < s2, positive if s1 > s2, 0 if s1 = s2
 */
int _strcmp(char *s1, char *s2)
{
	int count = 0;

	while (*(s1 + count) != '\0' && *(s2 + count) != '\0')
	{
		if (*(s1 + count) != *(s2 + count))
			return (*(s1 + count) - *(s2 + count));
		count++;
	}
	return (0);
}

