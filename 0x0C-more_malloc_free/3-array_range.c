#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to newly created array
 * if min > max or malloc fails, return NULL
 */
int *array_range(int min, int max)
{
	int *array;
	int i;

	if (min > max)
		return (NULL);
	ray = malloc(sizeof(*array) * ((max - min) + 1));
	if (array == NULL)
		return (NULL);
	for (i = 0; min <= max; i++, min++)
		array[i] = min;
	return (array);
}

