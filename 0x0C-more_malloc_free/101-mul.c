#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _print - moves a string one place to the left and prints the string
 * @str: string to move
 * @l: size of string
 *
 * Return: void
 */
void _print(char *str, int l)
{
	int i, j;

	i = j = 0;
	while (i < l)
	{
		if (str[i] != '0')
			j = 1;
		if (j || i == l - 1)
			_putchar(str[i]);
		i++;
	}
	_putchar('\n');
	free(str);
}

/**
 * mul - multiplies a char with a string and places the answer into dest
 * @n: char to multiply
 * @num: string to multiply
 * @i: last non NULL index of num
 * @dest: destination of multiplication
 * @dest_index: highest index to start addijon
 *
 * Return: pointer to dest, or NULL on failure
 */
char *mul(char n, char *num, int i, char *dest, int dest_index)
{
	int j, k, mul, multiply, add, count;

	multiply = count = 0;
	for (j = i, k = dest_index; j >= 0; j--, k--)
	{
		mul = (n - '0') * (num[j] - '0') + multiply;
		multiply = mul / 10;
		add = (dest[k] - '0') + (mul % 10) + count;
		count = add / 10;
		dest[k] = add % 10 + '0';
	}
	for (count += multiply; k >= 0 && count; k--)
	{
		add = (dest[k] - '0') + count;
		count = add / 10;
		dest[k] = add % 10 + '0';
	}
	if (count)
		return (NULL);
	return (dest);
}

/**
 * check_for_digits - checks the arguments to ensure they are digits
 * @av: pointer to arguments
 *
 * Return: 0 if digits, 1 if not
 */
int check_for_digits(char **av)
{
	int i, j;

	for (i = 1; i < 3; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
		}
	}
	return (0);
}

/**
 * init - initializes a string
 * @str: string to initialize
 * @l: length of string
 *
 * Return: void
 */
void init(char *str, int l)
{
	int i;

	for (i = 0; i < l; i++)
		str[i] = '0';
	str[i] = '\0';
}

/**
 * main - multiply two numbers
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: zero, or exit status of 98 if failure
 */

int main(int argc, char *argv[])
{
	int n1, n2, ln, j, i;
	char *a;
	char *t;
	char str[] = "Error\n";

	if (argc != 3 || check_for_digits(argv))
	{
		for (j = 0; str[j]; j++)
			_putchar(str[j]);
		exit(98);
	}
	for (n1 = 0; argv[1][n1]; n1++)
		;
	for (n2 = 0; argv[2][n2]; n2++)
		;
	ln = n1 + n2 + 1;
	a = malloc(ln * sizeof(char));
	if (a == NULL)
	{
		for (j = 0; str[j]; j++)
			_putchar(str[j]);
		exit(98);
	}
	init(a, ln - 1);
	for (j = n2 - 1, i = 0; j >= 0; j--, i++)
	{
		t = mul(argv[2][j], argv[1], n1 - 1, a, (ln - 2) - i);
		if (t == NULL)
		{
			for (j = 0; str[j]; j++)
				_putchar(str[j]);
			free(a);
			exit(98);
		}
	}
	_print(a, ln - 1);
	return (0);
}

