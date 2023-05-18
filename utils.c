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


