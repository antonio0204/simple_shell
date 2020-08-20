#include "shell.h"

/**
 * print_prompt - print $ and wait for the user to type something.
 * Return: NULL or line string
 */

char *print_prompt(void)
{
	char *line_cmd = NULL;
	size_t nbytes = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&line_cmd, &nbytes, stdin) == -1)
	{
		free(line_cmd);
		return (NULL);
	}

	return (line_cmd);
}
