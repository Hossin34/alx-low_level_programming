#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @str: str
 * Return: int
 */
int _atoi(char *str)
{
	unsigned int count = 0, size = 0, num = 0, sign = 1, mult = 1, i;

	while (*(str + count) != '\0')
	{
		if (size > 0 && (*(str + count) < '0' || *(str + count) > '9'))
			break;

		if (*(str + count) == '-')
			sign *= -1;

		if ((*(str + count) >= '0') && (*(str + count) <= '9'))
		{
			if (size > 0)
				mult *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		num = num + ((*(str + i) - 48) * mult);
		mult /= 10;
	}
	return (num * sign);
}

