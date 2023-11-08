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

int _write_buffer(char *c);
void prompt_msg(void);
void get_input(char *buffer, size_t bufsize);
int str_length(char *c);
void run_command(const char *buffer, char **argv, char *env[]);

#endif
