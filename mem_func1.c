#include "shell.h"

/**
* _memset - fills the first n bytes of the memory area
* pointed to by s with the constant byte b
* @n: input
* @s: input
* @b: input
* Return: pointer
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
* _realloc - reallocates a memory block using malloc and free
* @ptr: input
* @old_size: input
* @new_size: input
* Return: Always 0
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *a;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	a = malloc(new_size);
	if (!a)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;

	while (old_size--)
		a[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (a);
}

/**
 * free_all - frees a array of strings
 * @arr: array of strings
 */
void free_all(char **arr)
{
	char **a = arr;

	if (!arr)
		return;
	while (*arr)
		free(*arr++);
	free(a);
}
