#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PATH_MAX 4096

extern char **environ;

/* function declarations */
int execute_command(char *command);
char *find_full_path(char *command);
void print_error(char *command, char *error_message);
int exit_shell(void);
void env_shell(void);
int my_strcmp(const char *s1, const char *s2);
int count_arguments(char *command, char *delim);

#endif /* SHELL_H */


