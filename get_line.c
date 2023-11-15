#include "main.h"

/**
 * _getline - read one line from the prompt.
 * @data: struct for the program's data
 *
 * Return: reading counting bytes.
 */
int _getline(program_data *data)
{
	char buffer[BUFFER_SIZE];
	static char *commands[10] = {NULL};
	ssize_t bytes;
	int i = 0;
	int j = 0;
	int c = 0;

	if (!commands[0])
	{
		while (commands[i])
		{
			free(commands[i]);
			commands[i] = NULL;
			i++;
		}
		bytes = read(data->descriptor, &buffer, BUFFER_SIZE - 1);
		if (bytes == 0)
			return (-1);

		if (strlen(buffer) == 1)
			return (0);
		commands[j] = strdup(strtok(buffer, "\n;"));
		while (commands[++j])
			commands[j] = strdup(strtok(NULL, "\n;"));
	}
	data->input = commands[0];
	for (i = 0, c = 1; commands[i]; i++, c++)
		commands[i] = commands[c];
	return (strlen(data->input));
}

