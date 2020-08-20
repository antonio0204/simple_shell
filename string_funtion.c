#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *conc;
	unsigned int len1 = 0, len2 = 0, i;

	if (dest == NULL)
		dest = "";
	if (src == NULL)
		src = "";
	while (dest[len1])
		len1++;
	while (src[len2])
		len2++;
	conc = malloc(sizeof(char) * (len1 + (len2 + 1)));
	if (conc == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		conc[i] = dest[i];
		i++;
	}
	i = 0;
	while (i <= len2)
	{
		conc[len1] = src[i];
		i++;
		len1++;
	}
	return (conc);

}

/**
 * _strcmp - compares two strings
 * @dest: first string to compare
 * @src: second string to compare
 *
 * Return: less than 0 if dest is less than src, 0 if they're equal,
 * more than 0 if dest is greater than src
 */
int _strcmp(char *dest, char *src)
{
	while (*dest == *src)
	{
		if (*dest == '\0')
			return (0);
		dest++;
		src++;
	}
	return (*dest - *src);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *           which contains a copy of the string given as a parameter.
 * @str: string to copy
 *
 * Return: Pointer to newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		s[i] = str[i];
		i++;
		len--;
	}
	s[i] = '\0';
	return (s);
}

/**
 * _strlen - returns the length of a string
 * @s: string to get its length
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int i, len;

	i = 0;
	while (s[i] != '\0')
	{
		len = i + 1;
		i++;
	}
	return (len);
}
