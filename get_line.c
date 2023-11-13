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
	static char operators[10] = {'\0'};
	ssize_t bytes;
	int i = 0;
	int j = 0;
	int c = 0;
	
	if (!commands[0] || operators[0] == '&' || operators[0] == '|')
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

		commands[j] = strdup(strtok(buffer, "\n;"));
		while (commands[++j])
		{
			commands[j] = strdup(strtok(NULL, "\n;"));
			j = _ops(commands, i, operators);
		}
	}
	data->input = commands[0];
	for (i = 0, c = 1; commands[i]; i++, c++)
	{
		commands[i] = commands[c];
		operators[i] = operators[c];
	}
	printf("%s", data->input);
	exit(0);
}

int _ops(char *commands[], int j, char operators[])
{
	char *temp;
	int i;
	while (commands[j] != NULL && commands[j][i])
	{
		if ((commands[j][i] == '&' && commands[j][i + 1] == '&') || (commands[j][i] == '|' && commands[j][i + 1] == '|'))
		{
			temp = commands[j];
			operators[j] = commands[j][i];
			commands[j][i] = '\0';
			commands[j] = strdup(commands[j]);
			commands[j + 1] = strdup(temp + i + 2);
			j++;
			free(temp);
			i = 0;
		}
		i++;
	}

	return (j);
}
