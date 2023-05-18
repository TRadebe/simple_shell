#include "shell.h"

/**
 * change_directory - Changes the current directory of the process.
 * @directory: The directory path to change to.
 *
 * Return: None.
 */
void change_directory(const char *directory);

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
if (argc == 1)
{
change_directory(getenv("HOME"));
}
else if (argc == 2)
{
change_directory(argv[1]);
}
else
{
fprintf(stderr, "cd: Too many arguments\n");
return (1);
}

return (0);
}

/**
 * change_directory - Changes the current directory of the process.
 * @directory: The directory path to change to.
 *
 * Description:
 *   - If @directory is "-", changes to the previous directory.
 *   - If @directory is not provided or empty, changes to the home directory.
 *   - Updates the PWD and OLDPWD environment variables.
 *
 * Return: None.
 */
void change_directory(const char *directory)
{
char *prev_directory = NULL;
char *current_directory = NULL;

if (strcmp(directory, "-") == 0)
{
directory = getenv("OLDPWD");
if (directory == NULL)
{
fprintf(stderr, "cd: OLDPWD not set\n");
exit(1);
}
}

if (directory == NULL || strlen(directory) == 0)
{
directory = getenv("HOME");
if (directory == NULL)
{
fprintf(stderr, "cd: HOME not set\n");
exit(1);
}
}

prev_directory = getcwd(NULL, 0);
if (prev_directory == NULL)
{
perror("cd: Failed to get current directory");
exit(1);
}

if (chdir(directory) != 0)
{
perror("cd");
free(prev_directory);
exit(1);
}

current_directory = getcwd(NULL, 0);
if (current_directory == NULL)
{
perror("cd: Failed to get current directory");
chdir(prev_directory);
free(prev_directory);
exit(1);
}

setenv("OLDPWD", prev_directory, 1);
setenv("PWD", current_directory, 1);

free(prev_directory);
free(current_directory);
}
