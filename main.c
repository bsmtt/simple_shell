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
	program_data data, *data_p = &data;
	(void) env;

	set_program_data(&data, argc, argv);
	while (1)
	{
		_getline(data_p);
		printf("%s", data_p->input);
	}

	return (0);
}

