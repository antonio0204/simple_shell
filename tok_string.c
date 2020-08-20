#include "shell.h"

/**
 * tok_string - creates an array of string
 * @line_cmd: string
 * Return: array of string or NULL
 */

char **tok_string(char *line_cmd)
{
	char **arg = NULL, *token = NULL;
	size_t count = 0, space = 0;

	if (line_cmd == NULL)
		return (NULL);

	for (count = 0; line_cmd[count]; count++)
	{
		if (line_cmd[count] == ' ')
			space++;
	}
	if ((space + 1) == _strlen(line_cmd))
		return (NULL);
	arg = malloc(sizeof(char *) * (space + 2));
	if (arg == NULL)
		return (NULL);

	token = strtok(line_cmd, " \n\t\r");
	for (count = 0; token != NULL; count++)
	{
		arg[count] = token;
		token = strtok(NULL, " \n\t\r");
	}
	arg[count] = NULL;
	return (arg);
}
