#include "shell.h"
/**
 * *get_line - get the line from the imput
 *
 * Return: Buffer with the line
 */
char *get_line(void)
{
	size_t len = 0;
	int n;
	char *buffer = NULL;

	n = getline(&buffer, &len, stdin);
	if (n == EOF)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	if (n == 0)
		return (NULL);
	return (buffer);
}
