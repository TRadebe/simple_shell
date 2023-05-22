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
 * exit_shell_with_status - Exit the shell with a specified status
 * @exitStatus: The exit status to be returned by the shell
 *
 * Exits the shell with the specified exit status.
 *
 * @exitStatus: The exit status value to be returned
 */
void exit_shell_with_status(int exitStatus)
{
	exit(exitStatus);
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

/**
 * my_strncmp - Compare two strings up to a specified length
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 * @n: Maximum number of characters to compare
 *
 * Compare two strings `s1` and `s2` up to length `n`.
 *
 * Return: Difference between the first differing characters or 0 if equal
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((int)(*s1 - *s2));
}


