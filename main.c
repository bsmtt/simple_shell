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
	(void) env;

	set_program_data(&data, argc, argv);

	return (0);
}
/**
 * set_program_data - set program data
 * @data: struct to save program data
 * @argc: number of arguments
 * @argv: values of arguments
 * @env: environment variables
 */
void set_program_data(program_data *data, int argc, char *argv[])
{
	int i;
	data->command_tokens = NULL; /* tokenize command */

	data->alias_list = malloc(sizeof(char *) * 30);
	if (!data->alias_list)
	{
		_write_error(argv[0]);
		exit(127);
	}
	for (i = 0; i < 20; i++)
		data->alias_list[i] = NULL;

	/* check if interactive mood*/
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
		data->descriptor = STDIN_FILENO; /*interactive mood*/
	else
	{
		data->descriptor = open(argv[1], O_RDONLY);
		if (data->descriptor == -1) /* error opening file */
		{
			_write_error(argv[0]); /* wrong command is entered*/
			_write_error(": ");
			_write_error(argv[1]);
			_write_error(": Command not found\n");
			exit(127);
		}
	}
}
