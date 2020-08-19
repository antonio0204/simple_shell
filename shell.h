#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
extern char *program_invocation_name;

/**
 * struct builtin_s - struct to find a built_in command
 *and its associated funct
 *
 * @command: command written by the user
 * @fp: The function associated
 */
typedef struct builtin_s
{
	char *command;
	void (*fp)(char **);
} builtin_t;

int _putchar(char c);
void _puts(char *str);
void print_prompt(char *s);
char *get_line(void);
char **tok_string(char *line);
void exec_cmd(char **argv);
char *inclu_path(char *cmd);
char *_getenv(char *name);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strlen(const char *s);
int is_builtin(char **argv);
char *_strdup(char *str);
int _atoi(char *s);




#endif /*SHELL_H*/
