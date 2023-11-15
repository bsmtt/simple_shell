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
	prompt_loop(&data, env);
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
void prompt_loop(program_data *data, char *env[])
{
	size_t size = 40;
	int len;

	data->input = malloc(size * sizeof(char));
	if (!data->input)
	{
		perror("error when allocate input line");
		exit(1);
	}
	while (1)
	{
		prompt_msg(0);
		/*getline(&data->input, &size, stdin);*/
		len = _getline(data);
		if (len == 1 || len == 0)
			continue;

		if (len)
		{
			tokenize_command(data);
			run_command(data, env);
			if (!data->is_current_file && data->descriptor == STDIN_FILENO)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (feof(stdin))
			{
				perror("\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				exit(EXIT_SUCCESS);
			}
		}
	}
}
