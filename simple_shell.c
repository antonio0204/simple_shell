#include "shell.h"

/**
 *main - Principal file for shell
 *@ac: Argument count
 *@av: Argument value
 *@env: Environment
 *Return: 0
 */

int main(int ac, char **av, char **env)
{
	char *line_cmd = NULL, **arg = NULL;
	int i = 0, _exit = 0, count = 0;
	(void)ac;

	
	while (1)
	{
		line_cmd = print_prompt();
		if (line_cmd)
		{
			i++;
			arg = tok_string(line_cmd);
			if (!arg)
			{
				free(line_cmd);
				continue;
			}
			if (!_strcmp(arg[0], "exit"))
				exit_b(arg, line_cmd, _exit, i, av);
			if (!_strcmp(arg[0], "env"))
				display_env(env);
			else
			{
				count = include_path(&arg[0], env);
				_exit = execute(arg, av, env, line_cmd, i, count);
				if (count == 0)
					free(arg[0]);
			}
			free(arg);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		free(line_cmd);
	}
	return (_exit);
}
