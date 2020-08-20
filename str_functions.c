#include "shell.h"

/**
 * _strlen - Entry point
 * Returning lenght of string
 * Return: a
 * @s: string 'Holberton!'
 */

size_t _strlen(char *s)
{
	size_t a = 0;

	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

/**
 *_strncmp - Function that compares a string
 *@s1: string *
 *@s2: string *
 *@n: n of bytes
 *Return: i or 0
 */

size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * _strcpy - function that copies the string pointed to by
 *src
 *@dest: char*
 *@src: char *
 * Return: nothing
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 *_strcmp - Function that compares a string
 *@s1: string *
 *@s2: string *
 *Return: i or 0
 */

size_t _strcmp(char *s1, char *s2)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0'; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 *_strcat - Concatenates two strings
 *@src: string
 *@dest: string
 *Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;


	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}
