#include "main.h"

/**
 * _write_txt - write character
 * @c: charcter to concatenate
 * Return: number of printed chars
 */
int _write_txt(char *c)
{
	return (write(STDOUT_FILENO, c, str_length(c)));
}
/**
 * _write_error - write character
 * @c: charcter to concatenate
 * Return: number of printed chars
 */
int _write_error(char *c)
{
	return (write(STDERR_FILENO, c, str_length(c)));
}