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

/**
 * parse_command - seprate string
 * @data: a pointer to the program's data
 * Return: an array of the different parts of the string
 */
void parse_command(buffer_data *data)
{
	char *del = " ";
	int i = 0, c = 0;
	char* argument;
	
	printf("y");
	while(data->buffer[i])
	{
		if (data->buffer[i] == del[0])
			c++;
		i++;
	}
	 printf("y");
	data->arguments = malloc((c + 2) * sizeof(char *));
	if (!data->arguments)
	{
		printf("y");
		exit(127);
	}
	
	argument = strtok(data->buffer, del);
	data->arguments[0] = strdup(argument);
	data->command = strdup(argument);

	i = 1;
	while (data->arguments[i])
	{
		argument = strtok(NULL, del);
		data->arguments[i] = strdup(argument);
		i++;
	}

}
