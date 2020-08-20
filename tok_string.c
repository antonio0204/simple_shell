#include "shell.h"
/**
 * tok_string - function separate the string in new strings
 * @line: string
 * Return:  a pointer to strings.
 */
char **tok_string(char *line)
{
	char *dlm = " \t\n\r\a";
	char *commnd;
	int count = 0;
	char **line_cmd =  malloc(sizeof(char *) * _strlen(line) + 1);

	if (line_cmd == NULL)
	{
		/*free(line_cmd);*/
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
	/*free(line_cmd);*/

	return (line_cmd);
}
