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
	program_data data;
	(void)env;

	signal(SIGINT, prompt_msg);

	set_program_data(&data, argc, argv);
	prompt_loop(&data);
	return (0);
}
/**
 * prmpt_msg - write prompt message
 * @opr: not used input
 */
void prompt_msg(int opr)
{
	(void)opr;
	_write_txt("\n");
	_write_txt("$ ");
}
/**
 * prompt_loop - loop to show prompt
 * @data: program data
 */
void prompt_loop(program_data *data)
{
	size_t size = 40;
	size_t command_length;

	data->input = malloc(size * sizeof(char));
	if (!data->input)
	{
		perror("error when allocate input line");
		exit(1);
	}

	while (1)
	{
		prompt_msg(0);
		/*command_length = _getline(data);*/

		command_length = getline(&data->input, &size, stdin);
		if (command_length && command_length > 0)
		{
			tokenize_command(data);
			printf("%s", data->command_tokens[0]);
			continue;
		}
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
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
