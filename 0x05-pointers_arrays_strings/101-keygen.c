#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates keygen.
 * Return: 0 on success
 */

int main(void)
{
	int sum = 0;

	srand(time(NULL));

	while (sum < 2772)
	{
		int r = rand() % 128;

		if (sum + r > 2772)
			r = 2772 - sum;
		sum += r;
		putchar(r);
	}
	putchar(2772 - sum);

	return (0);
}

