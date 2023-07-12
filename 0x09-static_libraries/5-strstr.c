#include "main.h"
/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring to search for
 * Return: pointer to beginning of needle in haystack or NULL if no match
 */
char *_strstr(char *haystack, char *needle)
{
	char *tmp;
	char *tmp1;

	while (*haystack != '\0')
	{
		tmp = haystack;
		tmp1 = needle;
		while (*haystack != '\0' && *tmp1 != '\0' && *haystack == *tmp1)
		{
			haystack++;
			tmp1++;
		}
		if (!*tmp1)
			return (tmp);
		haystack = tmp + 1;
	}
	return (0);
}

