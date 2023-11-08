#include "main.h"

/**
 * str_length - get string length.
 * @c: string to get length
 * Return: length of string.
 */
int str_length(char *c)
{
    int i;
    for (i = 0; c[i]; i++)
        ;
    return i;
}