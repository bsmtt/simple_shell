#include "main.h"

/**
 * str_length - get string length.
 * @c: string to get length
 * Return: length of string.
 */
int str_length(char *c)
{
	int i;

	for (i = 0; c[i]; i++)
		;
	return (i);
}
/**
 * str_clone - clone string
 * @c: string to clone
 * Return: new string
 */
char *str_clone(char *c)
{
	char *result;
	int i = 0, length = str_length(c) + 1;

	if (!c)
		return (NULL);

	result = malloc(sizeof(char) * length);
	if (!result)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	while (c[i])
	{
		result[i] = c[i];
		i++;
	}

	return (result);
}
