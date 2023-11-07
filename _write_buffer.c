#include "main.h"

/**
 * _write_buffer - write character
 * @c: charcter to concatenate
 * Return: void
 */
void _write_buffer(char c)
{
	static char buffer[1024];
	static int bufferCount;

	if (bufferCount == 1024 || !c)
	{
		write(1, buffer, bufferCount);
		bufferCount = 0;
	}

	buffer[bufferCount] = c;
	bufferCount = bufferCount + 1;
}
