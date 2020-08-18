#include "shell.h"

/**
 * display_env - This funcition prints in the stdout
 * the enviromental variables.
 * @args: Pointer with the direction to free  the allocated memory for
 * the  arguments passed to the program.
 * Return: None.
 */
void display_env(char __attribute__((__unused__)) **args)
{
	char **ep;

	for (ep = environ; *ep != NULL; ep++)
	{
		_puts(*ep);
		_putchar('\n');
	}
}
/**
 * exit_handler - this function closes the prompt when the exit cmd is passed
 * @args: Pointer with the direction to free  the allocated memory for
 * the  arguments passed to the program.
 * Return: None
 */
void exit_handler(char **args)
{
	int exit_status = 0, len1 = 0, len2 = 0;

	if (args[1] == NULL)
	{
		free(*args);
		exit(EXIT_SUCCESS);
	}

	exit_status = _atoi(args[1]);
	if (exit_status == -1)
	{
		len1 = _strlen(program_invocation_name);
		len2 = _strlen(": 1: exit: Illegal number: ");
		write(STDERR_FILENO, program_invocation_name, len1);
		write(STDERR_FILENO, ": 1: exit: Illegal number: ", len2);
		write(STDERR_FILENO, args[1], _strlen(args[1]));
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		free(*args);
		exit(exit_status);
	}
}
/**
 * is_builtin - checks if the argument is a builtin
 * @argv: builtin to search
 *
 * Return: 0 if a builtin is founded, -1 if not.
 */
int is_builtin(char **argv)
{
	builtin_t builtin[] = {
		{"exit", exit_handler},
		{"env", display_env},
		{NULL, NULL},
	};
	int i = 0;

	while (builtin[i].command != NULL)
	{
		if (_strcmp(*argv, builtin[i].command) == 0)
		{
			builtin[i].fp(argv);
			return (0);
		}
		i++;
	}
	return (-1);
}
