#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: str
 * Return: Void
 */
void puts_half(char *str)
{
	int i = 0, i;

	while (i >= 0)
	{
		if (str[i] == '\0')
			break;
		i++;
	}

	if (i % 2 == 1)
		i = i / 2;
	else
		i = (i - 1) / 2;

	for (i++; i < i; i++)
		_putchar(str[i]);
	_putchar('\n');
}
