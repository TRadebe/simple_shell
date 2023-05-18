#include "shell.h"

/**
 * check_absolute_path - Check if the command is an absolute path
 * @command: The command to check
 *
 * Return: The absolute path if command exists and is executable,
 * otherwise NULL
 */
char *check_absolute_path(char *command)
{
	if (access(command, X_OK) == 0)
		return (strdup(command));

	return (NULL);
}

/**
 * construct_full_path - Construct the full path
 * by appending directory and command
 * @directory: The directory to append
 * @command: The command to append
 *
 * Return: The full path constructed by appending directory and command
 */
char *construct_full_path(const char *directory, const char *command)
{
	size_t dir_len = strlen(directory);
	size_t cmd_len = strlen(command);
	size_t full_path_len = dir_len + 1 + cmd_len + 1;
	char *full_path = malloc(full_path_len);

	if (full_path == NULL)
		return (NULL);

	strcpy(full_path, directory);
	strcat(full_path, "/");
	strcat(full_path, command);

	return (full_path);
}

/**
 * find_full_path - Find the full path of a command
 * @command: The command to find the full path for
 *
 * Return: The full path of the command, or NULL if not found
 */
char *find_full_path(char *command)
{
	char *path = getenv("PATH");
	char *dir;
	char *full_path;

	if (command[0] == '/')
		return (check_absolute_path(command));

	full_path = malloc(PATH_MAX);
	if (full_path == NULL)
		return (NULL);

	while ((dir = strtok(path, ":")) != NULL)
	{
		path = NULL;
		full_path = construct_full_path(dir, command);

		if (full_path != NULL && access(full_path, X_OK) == 0)
			return (full_path);
	}

	return (NULL);
}

