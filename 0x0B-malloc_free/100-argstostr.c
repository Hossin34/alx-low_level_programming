#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to new string, or NULL if error
 */
char *argstostr(int ac, char **av)
{
	char *args;
	int c, i, j, k;

	if (ac == 0)
		return (NULL);
	for (c = i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			return (NULL);
		for (j = 0; av[i][j] != '\0'; j++)
			c++;
		c++;
	}
	args = malloc((c + 1) * sizeof(char));
	if (args == NULL)
	{
		free(args);
		return (NULL);
	}
	for (i = j = k = 0; k < c; j++, k++)
	{
		if (av[i][j] == '\0')
		{
			args[k] = '\n';
			i++;
			k++;
			j = 0;
		}
		if (k < c - 1)
			args[k] = av[i][j];
	}
	args[k] = '\0';
	return (args);
}

