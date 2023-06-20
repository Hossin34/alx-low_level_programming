#include "main.h"

/**
*main - Main function of the program
*
*
*Return: return 0 on success
*/
int main(void)
{
	char str[] = "_putchar";

	int i;

	for (i = 0; i < 8; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
	return (0);
}
