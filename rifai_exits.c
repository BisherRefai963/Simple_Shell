#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, b;
	char *c = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (c);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int d, e;
	char *f = dest;

	d = 0;
	e = 0;
	while (deste[d] != '\0')
		e++;
	while (src[e] != '\0' && j < n)
	{
		dest[d] = src[e];
		d++;
		e++;
	}
	if (e < n)
		dest[d] = '\0';
	return (f);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *e, char c)
{
	do {
		if (*e == c)
			return (e);
	} while (*e++ != '\0');

	return (NULL);
}
