#include "shell.h"

/**
 * execute_command - Execute a command with arguments
 * @command: A null-terminated string containing the command and its arguments
 * @program_name: The program name (argv[0])
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command, char *program_name)
{
	pid_t pid;
	char **args;

	args = parse_arguments(command);
	if (args == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		free(args);
		return (-1);
	}
	else if (pid == 0)
	{
		char *full_path = find_full_path(args[0]);

		if (full_path == NULL)
		{
			fprintf(stderr, "%s: %d: %s:  not found\n", program_name, 1,  args[0]);
			exit(127);
		}
		execute_child_process(full_path, args);
	}
	else
	{
		wait_for_child_process(pid);
	}

	free(args);
	return (0);
}

/**
 * execute_builtin_command - Execute a built-in shell command
 * @command: A null-terminated string containing the command
 *
 * Return: 0 on success, -1 on failure
 */
int execute_builtin_command(char *command)
{
	if (my_strncmp(command, "exit", 4) == 0)
	{
		if (command[4] == '\n' || command[4] == '\0' || command[4] == ' ')
		{
			if (command[4] == ' ')
			{
				int exitStatus = atoi(command + 5);

				exit_shell_with_status(exitStatus);
			}
			else
			{
				exit_shell();
			}
			return (0);
		}
	}
	else if (my_strcmp(command, "env") == 0)
	{
		env_shell();
		return (0);
	}
	return (-1);
}

/**
 * parse_arguments - Parse the command into arguments
 * @command: A null-terminated string containing the command
 *
 * Return: An array of null-terminated strings representing the arguments
 */
char **parse_arguments(char *command)
{
	int argc;
	char **args;
	int i;
	const char *delim = " \t\n";

	argc = count_arguments(command, " \t\n");
	args = malloc((argc + 1) * sizeof(char *));
	if (args == NULL)
	{
		return (NULL);
	}

	i = 0;
	args[i] = strtok(command, delim);
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, delim);
	}
	args[i] = NULL;

	return (args);
}

/**
 * execute_child_process - Execute the child process
 * @full_path: The full path of the command to be executed
 * @args: An array of null-terminated strings
 * representing the command arguments
 */
void execute_child_process(char *full_path, char **args)
{
	execve(full_path, args, environ);
	perror("execve");
	free(full_path);
	exit(EXIT_FAILURE);
}

/**
 * wait_for_child_process - Wait for the child process to complete
 * @pid: The process ID of the child process
 */
void wait_for_child_process(pid_t pid)
{
	int status;

	while (wait(&status) != pid)
	{
		/* Wait for the child process to complete */
	}
}

