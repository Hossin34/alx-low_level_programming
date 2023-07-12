#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of array
 * @height: height of array
 *
 * Return: pointer to 2D array, or NULL if failure
 */
int **alloc_grid(int width, int height)
{
	int **tab;
	int i, j;

	if (width < 1 || height < 1)
		return (NULL);
	tab = malloc(height * sizeof(int *));
	if (tab == NULL)
	{
		free(tab);
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		tab[i] = malloc(width * sizeof(int));
		if (tab[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			tab[i][j] = 0;
	return (tab);
}

