#include "shell.h"

/**
 * _getpath - Get Path
 * @env: Environment
 * Return: path or NULL
 */

char *_getpath(char **env)
{
	size_t nchar = 0, row = 0, column = 5;
	char *path = NULL;

	for (row = 0; _strncmp(env[row], "PATH=", 5); row++)
		;

	if (env[row] == NULL)
		return (NULL);
	if (env[row][5] == '\0')
		return (NULL);

	for (column = 5; env[row][column]; column++, nchar++)
		;

	path = malloc(sizeof(char) * (nchar + 1));

	if (path == NULL)
		return (NULL);

	for (column = 5, nchar = 0; env[row][column]; column++, nchar++)
		path[nchar] = env[row][column];

	path[nchar] = '\0';
	return (path);
}
