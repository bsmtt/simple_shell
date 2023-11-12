#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

#define BUFFER_SIZE 1024

typedef struct buffer
{
	char *buffer;
	char *command;
	char **arguments;
	int f_descriptor;
} buffer_data;

int _write_buffer(char *c);
void prompt_msg(void);
void get_input(char *buffer, size_t bufsize);
int str_length(char *c);
void run_command(buffer_data *data, char **argv, char *env[]);
char **get_command_sections(char *buffer);
void _free(buffer_data *data);
void print_env(char *env[]);
void parse_command(buffer_data *data);

#endif
