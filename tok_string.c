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
	int size = 128;

	char **line_cmd =  malloc(sizeof(char *) * size);

	if (line_cmd == NULL)
		exit(EXIT_FAILURE);

	commnd = strtok(line, dlm);
	line_cmd[0] = commnd;
	line_cmd[1] = NULL;
	return (line_cmd);
}
