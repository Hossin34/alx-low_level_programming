#include "main.h"

/**
 * print_alphabet - print alphabets in ascending order
 *
 * Return: 0 on success
 */

void print_alphabet(void)
{
	char alpha = 'a';

	while (alpha <= 'z')
	{
		_putchar (alpha);
		alpha++;
	}
	_putchar ('\n');
}
