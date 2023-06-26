#include "main.h"

/**
 * rev_string - reverses a string
 * @s: str
 * Return: Void
 */
void rev_string(char *s)
{
	int i = 0, j, k;
	char *str, temp;

	while (i >= 0)
	{
		if (s[i] == '\0')
			break;
		i++;
	}
	str = s;

	for (j = 0; j < (i - 1); j++)
	{
		for (k = j + 1; k > 0; k--)
		{
			temp = *(str + k);
			*(str + k) = *(str + (k - 1));
			*(str + (k - 1)) = temp;
		}
	}
}
