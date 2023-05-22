#include "shell.h"

/**
 * main - Simple Shell entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *command = NULL;
	size_t command_len = 0;
	ssize_t chars_read;
	int command_status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		chars_read = my_getline(&command, &command_len);
		if (chars_read == -1)
			break;
		if (my_strncmp(command, "exit", 4) == 0)
		{
			if (command[4] == '\n' || command[4] == '\0')
				exit_shell();
			else if (command[4] == ' ')
			{
				int exitStatus = atoi(command + 5);

				exit_shell_with_status(exitStatus);
			}
			free(command);
			command = NULL;
			command_len = 0;
			continue;
		}
		command_status = execute_command(command);
		if (command_status == -1)
			perror("Error executing command");

		free(command);
		command = NULL;
		command_len = 0;
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(command);
	return (0);
}


