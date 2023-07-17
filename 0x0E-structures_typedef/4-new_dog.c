#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog.
 * @name: name member.
 * @age: age member.
 * @owner: owner member.
 *
 * Return: pointer to new dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *t_dog;
	int i, j, k;

	t_dog = malloc(sizeof(*t_dog));
	if (t_dog == NULL || !(name) || !(owner))
	{
		free(t_dog);
		return (NULL);
	}
	for (j = 0; name[j]; j++)
		;
	for (k = 0; owner[k]; k++)
		;
	t_dog->name = malloc(j + 1);
	t_dog->owner = malloc(k + 1);
	if (!(t_dog->name) || !(t_dog->owner))
	{
		free(t_dog->owner);
		free(t_dog->name);
		free(t_dog);
		return (NULL);
	}
	for (i = 0; i < j; i++)
		t_dog->name[i] = name[i];
	t_dog->name[i] = '\0';
	t_dog->age = age;
	for (i = 0; i < k; i++)
		t_dog->owner[i] = owner[i];
	t_dog->owner[i] = '\0';
	return (t_dog);
}

