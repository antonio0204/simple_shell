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

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == EOF)
		{
			perror("./shell");
			free(argv[0]);
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
