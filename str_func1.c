#include "shell.h"

/**
* _putchar - prints a character
* @c: input
* Return: on success 1.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _puts - prints a string followed by a new line.
* @str: input
* Return: always 0.
*/

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str + 0);
		str++;
	}
	_putchar('\n');
}

/**
* *_strcpy - prints n elements of an array of integers, followed by a new line.
* @dest: input
* @src: input
* Return: character.
*/

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}

/**
* _strdup - returns a pointer to a newly allocated space in memory,
* which contains a copy of the string given as a parameter.
* @str: input
* Return: pointer to string
*/

char *_strdup(char *str)
{
	char *a;
	unsigned int i, n;

	if (str == NULL)
	{
		return ('\0');
	}
	n = 0;
	while (str[n])
		n++;

	a = malloc(n + 1);
	if (a == 0)
	{
		return ('\0');
	}


	for (i = 0; i < n; i++)
	{
		a[i] = str[i];
	}

	return (a);
	free(a);
}
