#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - displays the shell prompt
 */

void display_prompt(void)
{
char prompt[] = "#cisfun$ ";
write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * read_command - reads a command from the user
 * @line: pointer to a string buffer for the command
 * @bufsize: size of the string buffer
 * Return: number of characters read
 */

ssize_t read_command(char **line, size_t *bufsize)
{
ssize_t define;

define = getline(line, bufsize, stdin);
if (define == -1)
{
if (feof(stdin))
{
write(STDOUT_FILENO, "\n", 1);
exit(EXIT_SUCCESS);
}
else
{
perror("getline error");
exit(EXIT_FAILURE);
}
}

/* Remove the newline character from the input */
(*line)[strcspn(*line, "\n")] = '\0';

return (define);
}

/**
 * execute_command - executes a command in a child process
 * @command: name of the command to execute
 * @line: command line arguments
 */

void execute_command(char *command, char *line)
{
pid_t pid;
int status;

pid = fork();
if (pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0) /* Child process */
{
/* Build the full path to the command */
char full_command[MAX_COMMAND_LENGTH];
snprintf(full_command, MAX_COMMAND_LENGTH, "/bin/%s", command);

/* Execute the command */
if (execlp(full_command, line, (char *)NULL) == -1)
{
perror("execlp error");
exit(EXIT_FAILURE);
}
}
else /* Parent process */
{
/* Wait for the child process to finish */
waitpid(pid, &status, 0);

/* Print an error message if the command was not found */
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
{
char err_message[MAX_COMMAND_LENGTH];
snprintf(err_message, MAX_COMMAND_LENGTH, "%s: command not found\n", command);
write(STDOUT_FILENO, err_message, strlen(err_message));
}
}
}

/**
 * main - entry point for the shell
 *
 * Return: always 0
 */

int main(void)
{
char *line = NULL;
size_t bufsize = 0;


while (1)
{
display_prompt();
read_command(&line, &bufsize);

execute_command(line, line);
}

/* Free the memory allocated for the input line */
free(line);

return (0);
}
