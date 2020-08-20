#include "shell.h"

/**
 *exit_b - Built-in to exit
 *@arg: Arguments
 *@line_cmd: Input string
 *@_exit: Number of exit
 *@np: Number of process
 *@av: Name of program
 */

void exit_b(char **arg, char *line_cmd, int _exit, int np, char **av)
{
	int status = 0, idx;
	char *format = "%s: %d: exit: Illegal number: %d\n";
	char *format1 = "%s: %d: exit: Illegal number: %s\n";

	if (!arg[1])
	{
		free(line_cmd);
		free(arg);
		exit(_exit);
	}
	for (idx = 0; arg[1][idx] != '\0'; idx++)
	{
		if (arg[1][idx] < 48 && arg[1][idx] > 57)
		{
			fprintf(stderr, format1, av[0], np, arg[1]);
			free(line_cmd);
			free(arg);
			exit(2);
		}
	}
	status = atoi(arg[1]);
	if (status < 0)
	{
		status = 2;
		fprintf(stderr, format, av[0], np, status);
	}
	if (status == 1000)
		status = 232;

	free(line_cmd);
	free(arg);
	exit(status);
}

/**
 *display_env - Built-in to enviroment
 *@env: Enviroment
 *Return: 0
 */

void display_env(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], _strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}

/**
 *ctrl_c - To avoid closing the program when ctrl + c is pressed
 *@sigin: void
 */

void ctrl_c(int sigin)
{
	(void)sigin;

	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);
}
