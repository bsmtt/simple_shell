#include "main.h"

/**
 * _write_buffer - write character
 * @c: charcter to concatenate
 * Return: number of printed chars
 */
int _write_buffer(char *c)
{
	return (write(STDOUT_FILENO, c, str_length(c)));
}
