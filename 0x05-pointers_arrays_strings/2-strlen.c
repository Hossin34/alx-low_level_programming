#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: str
 * Return: length of str
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
