#include "main.h"
/**
 * set_program_data - set program data
 * @data: struct to save program data
 * @argc: number of arguments
 * @argv: values of arguments
 */
void set_program_data(program_data *data, int argc, char *argv[])
{
	data->command_tokens = NULL; /* tokenize command */
	data->is_current_file = 0;
	/* check if interactive mood*/
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		data->is_current_file = 1; /*interactive mood*/
	/* check if interactive mood*/
	if (argc == 1)
		data->descriptor = STDIN_FILENO;
	else
	{
		errno = 2;
		data->descriptor = open(argv[1], O_RDONLY);
		if (data->descriptor == -1) /* error opening file */
		{
			_write_error(argv[0]); /* wrong command is entered*/
			_write_error(": ");
			_write_error(argv[1]);
			_write_error(": Command not found\n");
			exit(errno);
		}
	}
}
/**
 * remove_program_data - remove saved program data
 * @data: struct of program data
 * @freeAll: int
 */
void remove_program_data(program_data *data, int freeAll)
{
	if (data->command_tokens)
		free_pointer_array(data->command_tokens);

	data->command_tokens = NULL;

	if (data->descriptor != STDIN_FILENO && freeAll)
	{
		close(data->descriptor);
		if (data->input)
			free(data->input);
		data->input = NULL;
	}
}
/**
 * free_pointer_array - free all string pointer in array
 * @arr: array of strings
 */
void free_pointer_array(char **arr)
{
	int i = 0;

	if (arr)
	{
		while (arr[i])
			free(arr[i]), i++;
		free(arr);
	}
}
