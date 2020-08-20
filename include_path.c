#include "shell.h"

/**
 *include_path - Concatenates paths
 *@arg: Command
 *@env: Envitonment
 *Return: 0 or -1
 */

int include_path(char **arg, char **env)
{
	char *token = NULL, *path = NULL, *dir = NULL;
	size_t folder, command;
	struct stat stat_buf;

	if (stat(*arg, &stat_buf) == 0)
		return (-1);
	path = _getpath(env);
	if (!path)
		path = "/bin:";
	token = strtok(path, ":");
	command = _strlen(*arg);
	while (token)
	{
		folder = _strlen(token);
		dir = malloc(sizeof(char) * (folder + command + 2));
		if (!dir)
		{
			free(path);
			return (-1);
		}
		dir = _strcpy(dir, token);
		_strcat(dir, "/");
		_strcat(dir, *arg);

		if (stat(dir, &stat_buf) == 0)
		{
			*arg = dir;
			free(path);
			return (0);
		}
		free(dir);
		token = strtok(NULL, ":");
	}
	free(path);
	return (-1);
}
