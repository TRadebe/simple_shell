#include "shell.h"

/**
 * exit_shell - Exits the shell
 *
 * Return: Always 0
 */
int exit_shell(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * env_shell - Print the current environment
 *
 * Return: None
 */

void env_shell(void)
{
	int fd = STDOUT_FILENO;
	char **env = environ;
	ssize_t len;

	while (*env)
	{
		len = strlen(*env);
		if (write(fd, *env, (ssize_t) len) != len || write(fd, "\n", 1) != 1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		env++;
	}
}

/**
 * find_full_path - Searches for a command
 *  in the directories listed in the PATH
 *
 * @command: String representing the name of the command to search for
 * Return:
 *   On success, this function returns a dynamically allocated string
 *   containing the full path to the executable file corresponding to the
 *   given command. The caller is responsible for freeing the memory allocated
 *   for the string. If no valid path is found, the function returns NULL
 */
char *find_full_path(char *command)
{
	char *path = getenv("PATH");
	char *dir;
	char *full_path;
	int i, j;

	/* check if command contains a full path */
	if (command[0] == '/')
	{
		/* check if file exist and is executable */
		if (access(command, X_OK) == 0)
		{
			return (strdup(command));
		}
		else
		{
			return (NULL);
		}
	}

	full_path = (char *) malloc(PATH_MAX + strlen(command) + 2);
	if (full_path == NULL)
	{
		return (NULL);
	}
	while ((dir = strtok(path, ":")) != NULL)
	{
		path = NULL;
		i = 0;

		while (dir[i] != '\0')
		{
			full_path[i] = dir[i];
			i++;
		}
		full_path[i] = '/';
		i++;
		j = 0;
		while (command[j] != '\0')
		{
			full_path[i] = command[j];
			i++;
			j++;
		}
		full_path[i] = '\0';
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
	}
	free(full_path);
	return (NULL);
}

/**
 * my_strcmp - compares two strings
 *
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: difference in ASCII value between
 * first different character or 0 if strings are equal
 */
int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)(*s1 - *s2));
}


