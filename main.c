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
	char buffer[BUFFER_SIZE];

	(void)argc;

	while (1)
	{
		_write_buffer("basma_shell$ ");
		get_input(buffer, sizeof(buffer));
		if (strcmp(buffer, "exit") == 0)
		{
			kill(getpid(), SIGINT);
			exit(EXIT_SUCCESS);
			break;
		}

		run_command(buffer, argv, env);
	}
	return (0);
}
/**
 * get_input - get input line from user
 * @buffer: command line
 * @bufsize: size of command line
 * Return: 0 on succes.
 */
void get_input(char *buffer, size_t bufsize)
{
	int characters = getline(&buffer, &bufsize, stdin);

	if (!characters)
	{
		if (feof(stdin))
		{
			_write_buffer("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_write_buffer("error");
			exit(EXIT_FAILURE);
		}
	}
	buffer[strcspn(buffer, "\n")] = '\0';
}
