#include "shell.h"

/**
 * count_arguments - Count the number of arguments in a string
 * @command: A null-terminated command containing the arguments
 * @delim: A null-terminated string containing the delimiters
 *
 * Return: The number of arguments in the string
 */
int count_arguments(char *command, char *delim)
{
	int argc = 0;
	int i;
	/* count number of arguments */
	for (i = 0; command[i]; i++)
	{
		if (delim[0] == command[i] || delim[1] ==
		command[i] || delim[2] == command[i])
		{
			if (i > 0 && (delim[0] != command[i - 1] &&
			delim[1] != command[i - 1] &&
			delim[2] != command[i - 1]))
				argc++;
		}
		else if (i == 0 || (delim[0] == command[i - 1] ||
		delim[1] == command[i - 1] || delim[2] == command[i - 1]))
			argc++;
	}

	return (argc);
}


