#include "shell.h"

/**
 * _putchar - writes the character c to standard output
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - prints a string to standard output
 * @str: pointer to the string to print
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
/**
 * print_prompt - prints a prompt for the shell
 * @s: pointer to the prompt to print
 */
void print_prompt(char *s)
{
	_puts(s);
}

