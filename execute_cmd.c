#include "shell.h"
/**
 * exec_cmd - function separate the string in new strings
 * @argv: matrix of command and argument
 *
 */
void exec_cmd(char **argv)
{
	pid_t pid;
	int status;
	char *cmd_path;

	pid = fork();
	if (pid == 0)
	{
		cmd_path = inclu_path(argv[0]);
		if (cmd_path == NULL)
		{
			perror("Command not found");
			free(argv[0]);
			free(argv);
			exit(EXIT_FAILURE);
		}

		if (execve(cmd_path, argv, environ) == EOF)
		{
			perror("./shell");
			free(cmd_path);
			free(argv);
			exit(EXIT_FAILURE);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else
		wait(&status);
}
