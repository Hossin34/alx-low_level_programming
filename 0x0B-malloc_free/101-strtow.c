#include "main.h"
#include <stdlib.h>
/**
 * ft_free - frees a 2 dimensional grid previously created by strtow
 * @grid: grid to free
 * @count: height of grid
 *
 * Return: void
 */
void ft_free(char **grid, unsigned int count)
{
	if (grid != NULL && count != 0)
	{
		for (; count > 0; count--)
			free(grid[count]);
		free(grid[count]);
		free(grid);
	}
}
/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **spl;
	unsigned int c, count, i, j, k;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (c = count = 0; str[c] != '\0'; c++)
		if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			count++;
	spl = malloc((count + 1) * sizeof(char *));
	if (spl == NULL || count == 0)
	{
		free(spl);
		return (NULL);
	}
	for (i = k = 0; i < count; i++)
	{
		for (c = k; str[c] != '\0'; c++)
		{
			if (str[c] == ' ')
				k++;
			if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			{
				spl[i] = malloc((c - k + 2) * sizeof(char));
				if (spl[i] == NULL)
				{
					ft_free(spl, i);
					return (NULL);
				}
				break;
			}
		}
		for (j = 0; k <= c; k++, j++)
			spl[i][j] = str[k];
		spl[i][j] = '\0';
	}
	spl[i] = NULL;
	return (spl);
}

