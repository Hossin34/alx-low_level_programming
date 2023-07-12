#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to concatenated string, or NULL if failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concated;
	unsigned int i, j, k, count;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;
	concated = malloc(sizeof(char) * (i + j + 1));
	if (concated == NULL)
	{
		free(concated);
		return (NULL);
	}
	for (k = 0; k < i; k++)
		concated[k] = s1[k];
	count = j;
	for (j = 0; j <= count; k++, j++)
		concated[k] = s2[j];
	return (concated);
}

