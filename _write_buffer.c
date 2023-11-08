#include "main.h"

/**
 * _write_buffer - write character
 * @c: charcter to concatenate
 * Return: void
 */
void _write_buffer(char *c)
{
	return (write(STDOUT_FILENO, c, str_length(c)));
}
