#include "shell.h"


static char buffer[BUFFER_SIZE];
static size_t position;
static ssize_t chars_read;

/**
 * read_buffer - Read characters from input into the buffer
 *
 * Return: 1 if successful, 0 if no more input, -1 on error
 */
static int read_buffer(void)
{
	position = 0;
	chars_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (chars_read <= 0)
	{
		return (chars_read == 0 ? 0 : -1); /* No more input or error */
	}
	return (1);
}

/**
 * search_newline - Search for newline character in the buffer
 *
 * Return: Position of the newline character, or -1 if not found
 */
static ssize_t search_newline(void)
{
	ssize_t i;

	for (i = position; i < chars_read; i++)
	{
		if (buffer[i] == '\n')
		{
			return (i);
		}
	}
	return (-1); /* Newline not found in the buffer */
}

/**
 * copy_line - Copy characters from the buffer to the line
 * @line: Pointer to the line being read
 * @line_size: Current size of the line
 * @start: Start position in the buffer to copy from
 * @end: End position in the buffer to copy to (inclusive)
 */
static void copy_line(char **line, size_t line_size,
ssize_t start, ssize_t end)
{
	ssize_t j, k;
	*line = realloc(*line, line_size + end - start + 2);
	if (*line == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}

	for (j = start, k = 0; j <= end; j++, k++)
	(*line)[line_size + k] = buffer[j];

	(*line)[line_size + end - start + 1] = '\0';
}

/**
 * my_getline - Custom implementation of the getline function
 *
 * @line: Pointer to store the read line
 * @line_size: Pointer to store the current size of the line
 *
 * Return: Number of characters read or -1 if there is no more input
 */
ssize_t my_getline(char **line, size_t *line_size)
{
	while (1)
	{
		ssize_t newline_pos;
		/* Check if there are no more characters in the buffer */
		if ((ssize_t)position >= chars_read)
		{
			if (read_buffer() <= 0)
			{
				if (*line_size > 0)
					return (*line_size);
				return (-1); /* No more input */
			}
		}

		newline_pos = search_newline();

		if (newline_pos != -1)
		{
			copy_line(line, *line_size, position, newline_pos);

			/* Update the buffer position for the next call */
			position = newline_pos + 1;

			return (*line_size);
		}

		copy_line(line, *line_size, position, chars_read - 1);
		*line_size += chars_read - position;

		/* Reset the buffer position */
		position = 0;
	}
}

