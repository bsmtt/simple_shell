#include "main.h"

/**
 * run_command - run command
 * @env: number of arguments
 * @argv: values of arguments
 * @buffer : buffer
 * Return: void on succes.
 */
void run_command(program_data *data, char *env[])
{
	pid_t pid;
	int status;
	char path[256];
	int found = 0;
	char *dpath;
	char *dir;

	dpath = str_clone(getenv("PATH"));
	dir = strtok(dpath, ":");
	
	if (strcmp(data->command_tokens[0], "exit") == 0)
	{
		exit(EXIT_FAILURE);
        }
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
		printf("Command not found: %s\n", data->command_tokens[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		_write_txt("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(path, data->command_tokens, env);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
