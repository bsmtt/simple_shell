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

	errno = 0;
	set_program_data(&data, argc, argv);
	prompt_loop(&data, argv, env);
	return (0);
}
/**
 * prompt_msg - write prompt message
 * @descriptor: not used input
 */
void prompt_msg(int descriptor)
{
	if (descriptor == STDIN_FILENO)
		_write_txt("$");
}
/**
 * prompt_loop - loop to show prompt
 * @argv: values of arguments
 * @data: program data
 * @env: environment variables
 */
void prompt_loop(program_data *data, char *argv[], char *env[])
{
	int len;

	while (1)
	{
		prompt_msg(data->descriptor);

		len = _getline(data);
		if (len == 1 || len == 0)
			continue;
		if (len == -1)
		{
			remove_program_data(data, 1);
			exit(errno);
		}
		else if (len > 1)
		{
			tokenize_command(data);
			run_command(data, argv, env);
			if (!data->is_current_file && data->descriptor == STDIN_FILENO)
			{
				remove_program_data(data, 1);
				exit(0);
			}
			remove_program_data(data, 0);
		}
	}
}
