#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of s2 to concatenate to s1
 *
 * Return: pointer to concatenated string
 * if malloc fails, status value is 98
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concated;
	unsigned int str1, str2, conc, i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (str1 = 0; s1[str1] != '\0'; str1++)
		;
	for (str2 = 0; s2[str2] != '\0'; str2++)
		;
	if (n > str2)
		n = str2;
	conc = str1 + n;
	concated = malloc(conc + 1);
	if (concated == NULL)
		return (NULL);
	for (i = 0; i < conc; i++)
		if (i < str1)
			concated[i] = s1[i];
		else
			concated[i] = s2[i - str1];
	concated[i] = '\0';
	return (concated);
}

