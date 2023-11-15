#include "main.h"

/**
 * run_command - run command
 * @data: program data
 * @env: environment variables array
 */
void run_command(program_data *data, char *argv[], char *env[])
{
	pid_t pid;
	int found = 0;
	int status;
	char path[256];
	char *dpath, *dir;

	dpath = str_clone(getenv("PATH"));
	dir = strtok(dpath, ":");
	handle_exit(data);
	while (dir != NULL)
	{
		snprintf(path, sizeof(path), "%s/%s", dir, data->command_tokens[0]);
		if (access(path, F_OK) == 0)
		{
			found = 1;
			break;
		}
		dir = strtok(NULL, ":");
	}
	if (!found)
	{
		snprintf(path, sizeof(path), "%s", data->command_tokens[0]);
		if (access(path, F_OK) == 0)
			found = 1;
	}
	if (!found)
	{
		_write_txt(argv[0]);
		_write_txt(": No such file or directory\n");
		free(dpath);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		free(dpath);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		execve(path, data->command_tokens, env);
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			errno = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			errno = 128 + WTERMSIG(status);
	}
	free(dpath);
}

/**
 * handle_exit - run command
 * @data: program data
 * @data: data struct
 */
void handle_exit(program_data *data)
{
	if (strcmp(data->command_tokens[0], "exit") == 0)
	{
		remove_program_data(data, 1);
		exit(EXIT_FAILURE);
	}
}
