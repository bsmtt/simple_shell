#include "main.h"
/**
 * main - start point to program
 * @argc: number of arguments
 * @argv: values of arguments
 * @env: environment variables
 * Return: 0 on succes.
 */
int main(int argc, char *argv[], char *env[])
{
	program_data data, *data_p = &data;
	(void) env;

	while (1)
	{
		_getline(data_p);
		printf("%s", data_p->input);
	}


	set_program_data(&data, argc, argv);
	prompt_loop(&data);
	return (0);
}
/**
 * prompt_loop - loop to show prompt
 * @data: program data
 */
void prompt_loop(program_data *data)
{
	int command_length = 0;

	while (1)
	{
		_write_txt("Basma_shell$");
		/*command_length = _getline(data);*/

		if (command_length == EOF)
		{
			_write_txt("\n");
			exit(EXIT_SUCCESS);
		}
		if (command_length > 0)
		{
			tokenize_command(data);
			/* handle command tokens */
		}
	}
}
/**
 * tokenize_command - get command tokens
 * @data: program data
 */
void tokenize_command(program_data *data)
{
	int i, command_count = 1;
	char *del = " ";

	if (str_length(data->input))
		data->input[strcspn(data->input, "\n")] = '\0';

	for (i = 0; data->input[i]; i++)
		if (data->input[i] == del[0] && data->input[i + 1] && data->input[i + 1] != del[0])
			command_count++;

	data->command_tokens = malloc((command_count + 1) * sizeof(char *));
	if (!data->command_tokens)
	{
		perror("Error");
		exit(errno);
	}

	i = 0;
	data->command_tokens[i] = str_clone(strtok(data->input, del));
	while (data->command_tokens[i++])
		data->command_tokens[i] = str_clone(strtok(NULL, del));
}
