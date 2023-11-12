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

<<<<<<< HEAD
#define BUFFER_SIZE 1024

=======
/**
 * program_data - loop to show prompt
 * @command_tokens: command tokens
 * @input: input line
 * @descriptor: file descriptor
 */
>>>>>>> 0e3f3adf238606a996faf9c920b3a09517ef8f02
typedef struct program_data
{
	char **command_tokens;
	char *input;
	int descriptor;
} program_data;

void set_program_data(program_data *data, int argc, char *argv[]);
int _write_txt(char *c);
int _write_error(char *c);
int str_length(char *c);
void remove_program_data(program_data *data);
void free_pointer_array(char **arr);
<<<<<<< HEAD
int _ops(char *commands[], int j, char operators[]);
int _getline(program_data *data);
=======
void tokenize_command(program_data *data);
char *str_clone(char *c);
>>>>>>> 0e3f3adf238606a996faf9c920b3a09517ef8f02

#endif
