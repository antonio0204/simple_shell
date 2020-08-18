#include "shell.h"
/**
 * tok_string - function separate the string in new strings
 * @line: string
 * Return:  a pointer to strings.
 */
char **tok_string(char *line)
{
	char *dlm = " \n";
	char *commnd;
	int size = 128, count = 0;

	char **line_cmd =  malloc(sizeof(char *) * size);

	if (line_cmd == NULL)
	{
		free(line_cmd);
		exit(EXIT_FAILURE);
	}

	commnd = strtok(line, dlm);

	while (commnd)
	{
		line_cmd[count] = commnd;
		commnd = strtok(NULL, dlm);
		count++;
	}
	line_cmd[count] = NULL;

	return (line_cmd);
}
