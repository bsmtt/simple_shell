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
	_write_txt("$ ");
}
/**
 * prompt_loop - loop to show prompt
 * @data: program data
 */
void prompt_loop(program_data *data)
{
	size_t size = 40;

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

		/*getline(&data->input, &size, stdin);*/
		_getline(data);
		
		if (strlen(data->input))
		{
			continue;
		}
		if (str_length(data->input) > 0)
		{
			tokenize_command(data);
			continue;
		}
		printf("bad>>>");
		if (feof(stdin))
		{
			perror("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}
}
