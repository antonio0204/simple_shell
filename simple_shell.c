#include "shell.h"
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

		if (argv[0] == NULL || is_builtin(&argv[0]) == 0)
			continue;
		exec_cmd(argv);
		free(line_cmd);
		free(argv);
	}

	return (0);
}
