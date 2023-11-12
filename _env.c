#include "main.h"

/**
 * print_env - gets the value of an environment variable
 * @env: the environment variable of interest
 * Return: void
 */
void print_env(char *env[])
{
	int i = 0;
	while (env[i] != NULL)
	{
		_write_txt(env[i]);
		i++;
	}
}
