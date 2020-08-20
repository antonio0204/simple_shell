#include "shell.h"
/**
* free_args - get free arguments
* @args: double pointer to free
*
*/
void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	if (args)
		free(args);
}
/**
* main - simple command-line argument interpreter
* prints a prompt and waits for the user to input a command
* then creates a child process in which it executes the command
* Enter the "infinite" loop of the shell
* Return: always 0, for success
*
*/
int main(void)
{
	char **argv = NULL;
	char *line_cmd = NULL;

	while (1)
	{
		print_prompt("$ ");
		line_cmd = get_line();
		if (line_cmd == NULL)
			continue;
		argv = tok_string(line_cmd);

		if (!_strcmp(argv[0], "exit") && argv[1] == NULL)
			free(argv[0]), free(argv), exit(EXIT_SUCCESS);

		if (argv[0] == NULL || is_builtin(&argv[0]) == 0)
			continue;
		exec_cmd(argv);
		free(line_cmd);
		free(argv);
	}
	free_args(argv);

	return (0);
}
