#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char	digit;
	int	i;
	char	letter;

	digit = '0';
	letter = 'a';
	for (i = 0; i < 10; i++)
	{
		putchar(digit);
		digit++;
	}
	for (i = 0; i < 6; i++)
	{
		putchar(letter);
		letter++;
	}
	putchar('\n');
	return (0);
}
