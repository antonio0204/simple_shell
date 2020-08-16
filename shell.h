#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putchar(char c);
void _puts(char *str);
void print_prompt(char *s);
char *get_line(void);
char **tok_string(char *line);
void exec_cmd(char **argv);






#endif /*SHELL_H*/
