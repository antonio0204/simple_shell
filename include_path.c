#include "shell.h"
/**
 * div_dir_path - function separate the path in new strings
 * @path: string
 * Return:  a pointer to strings.
 */
char **div_dir_path(char *path)
{
	int pos = 0, size = 128;
	char *dlm = ":";
	char **directories = malloc(sizeof(char *) * size);
	char *dir_split;


	if (directories == NULL)
	{
		exit(EXIT_FAILURE);
	}
	dir_split = strtok(path, dlm);

	while (dir_split != NULL)
	{
		directories[pos] = dir_split;
		pos++;
		dir_split = strtok(NULL, dlm);

	}
	directories[pos] = NULL;
	return (directories);
}

/**
 * inclu_path - function to get the PATH enviroment.
 * @cmd: pointer to enviroment variable.
 * Return:  the PATH in a string.
 */
char *inclu_path(char *cmd)
{
	struct stat fileStat;
	char *dir_split = NULL;
	char **directories = NULL;
	char *final_cmd = NULL;
	char *slash_cmd = NULL;
	char *slash = "/";
	int i = 0;

	dir_split = _getenv("PATH");
	directories = div_dir_path(dir_split);
	if (stat(cmd, &fileStat) == 0)
		return (cmd);
	slash_cmd = _strcat(slash, cmd);

	while (directories[i])
	{
		final_cmd = _strcat(directories[i], slash_cmd);

		if (stat(final_cmd, &fileStat) == 0)
		{
			free(slash_cmd);
			free(directories);
			return (final_cmd);
		}
		free(final_cmd);
		i++;
	}
	free(slash_cmd);
	free(directories);
	return (NULL);
}
