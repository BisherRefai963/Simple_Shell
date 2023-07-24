#include "shell.h"

/**
* _strlen - returns the length of a string.
* @s: input
* Return: integer.
*/

int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
		++i;

	return (i);
}

/**
* _strcmp - compares two strings.
* @s1: input
* @s2: input
* Return: int
*/

int _strcmp(char *s1, char *s2)
{
	int i, n1, n2, f = 0;

	n1 = 0;
	while (s1[n1])
		n1++;

	n2 = 0;
	while (s2[n2])
		n2++;

	for (i = 0; i < n1; i++)
	{
		if ((int)s1[i] == (int)s2[i])
			;
		else if ((int)s1[i] < (int)s2[i])
		{
			f = -1;
			break;
		}
		else if ((int)s1[i] > (int)s2[i])
		{
			f = 1;
			break;
		}
	}
	return (f);
}

/**
* _strcat - concatenates two strings
* @dest: input
* @src: input
* Return: char.
*/

char *_strcat(char *dest, char *src)
{
	int n1, n2;

	n1 = 0;
	while (dest[n1])
		n1++;

	for (n2 = 0; src[n2]; n2++)
	{
		dest[n1++] = src[n2];
	}

	return (dest);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
