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
 * get_command_sections - get sections of string.
 * @buffer: string to get its sections
 * Return: sections of string.
 */
char **get_command_sections(char *buffer)
{
	char **sections;
	int i = 0;

	sections = malloc(sizeof(char *) * 20);
	if (sections)
		return (NULL);
	sections[i] = strtok(buffer, " ");
	while (sections[i])
	{
		_write_buffer(sections[i]);
		i++;
		sections[i] = strtok(NULL, " ");
	}
	return (sections);
}
