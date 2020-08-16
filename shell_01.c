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
	size_t len = 1024;
	char *buffer = malloc(1024);
	char *argv[] = {NULL, NULL};
	char *str;
	int status;

	if (buffer == NULL)
		return (0);
	while (1)
	{
		printf("#cisfun$ ");
		getline(&buffer, &len, stdin);
		str = strtok(buffer, "\n");
		argv[0] = str;
		if (fork() == 0)
		{
			if (execve(argv[0], argv, NULL) == EOF)
				perror("./shell");
		}
		else
			wait(&status);
	}
	free(buffer);
	return (0);
}
