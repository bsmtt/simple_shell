#include "main.h"

/**
 * run_comand - run command
 * @env: number of arguments
 * @argv: values of arguments
 * @buffer : buffer
 * Return: void on succes.
 */
void run_command(const char *buffer, char **argv, char *env[])
{
	pid_t pid = fork();
	int status;
	char path[256];

	if (pid == -1)
	{
		_write_buffer("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		snprintf(path, sizeof(path), "/bin/%s", buffer);
		printf("%s", path);
		execve(path, argv, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}