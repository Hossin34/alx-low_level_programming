#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers
 * @arr: array
 * @n: n elements
 * Return: Void
 */
void print_array(int *arr, int n)
{
	int i = 0;

	for (; i < n; i++)
	{
		printf("%d", *(arr + i));
		if (i != (n - 1))
			printf(", ");
	}
	printf("\n");
}
