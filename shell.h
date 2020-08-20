#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
extern char **environ;

char *print_prompt(void);
char **tok_string(char *line_cmd);
int execute(char **arg, char **av, char **env, char *line_cmd, int np, int c);
char *_getpath(char **env);
int include_path(char **arg, char **env);
void exit_b(char **arg, char *line_cmd, int _exit, int np, char **av);
void display_env(char **env);

char *_strcat(char *dest, char *src);
size_t _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
size_t _strncmp(char *s1, char *s2, size_t n);
size_t _strlen(char *s);
void ctrl_c(int sigin);

#endif /* SHELL_H */
