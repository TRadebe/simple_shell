#include "shell.h"

/**
 * execute_command - Execute a command with arguments
 * @command: A null-terminated string containing the command and its arguments
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command)
{
	pid_t pid;
	int status;
	char *full_path;
	char **args;
	int argc = 0, i;
	const char *delim = " \t\n";

	/* Check for built-in commands */
	if (my_strcmp(command, "exit") == 0)
	{
		exit_shell();
		return (0);
	}
	else if (my_strcmp(command, "env") == 0)
	{
		env_shell();
		return (0);
	}

	/* count number of arguments */
	argc = count_arguments(command, " \t\n");
    /* cast to (void) to silence unused variable warnings */
	(void)argc;
	args = malloc((argc + 1) * sizeof(char *));
	if (args == NULL)
		return (-1);

	/* parse command and arguments */
	i = 0;
	args[i] = strtok(command, delim);
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, delim);
	}
	args[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		free(args);
		return (-1);
	}
	else if (pid == 0)
	{
		/* Child process */
		full_path = find_full_path(args[0]);
			if (full_path == NULL)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				exit(127);
			}
			else
			{
				execve(full_path, args, environ);
				perror("execve");
				free(full_path);
				exit(EXIT_FAILURE);
			}
	}
	else
	{
		/* Parent process */
		while (wait(&status) != pid)
		{
		}
	}

	free(args);
	return (0);
}


