#include "main.h"

/**
 * rev_string - reverses a string
 * @s: str
 * Return: Void
 */
void rev_string(char *s)
{
	int i = 0, i, j;
	char *str, temp;

	while (i >= 0)
	{
		if (s[i] == '\0')
			break;
		i++;
	}
	str = s;

	for (i = 0; i < (i - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
