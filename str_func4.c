#include "shell.h"

/**
* _strncpy - copies a string
* @dest: input
* @src: input
* @n: input
* Return: char.
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

/**
* _strncat - concatenates two strings
* @dest: input
* @src: input
* @n: input
* Return: char.
*/

char *_strncat(char *dest, char *src, int n)
{
	int n1, n2;

	n1 = 0;
	while (dest[n1])
		n1++;

	for (n2 = 0; n2 < n && src[n2] != '\0'; n2++)
	{
		dest[n1++] = src[n2];
	}

	return (dest);
}

/**
* _strchr - locates a character in a string.
* @s: input
* @c: input
* Return: pointer
*/

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return ('\0');
}
