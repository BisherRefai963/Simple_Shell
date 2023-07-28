#include "shell.h"

/**
 **rifai_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *rifai_memset(char *l, char k, unsigned int o)
{
	unsigned int q;

	for (q = 0; q < o; q++)
		l[q] = k;
	return (l);
}

/**
 * rifai_ffree - frees a string of strings
 * @pp: string of strings
 */
void rifai_ffree(char **ppr)
{
	char **y = ppr;

	if (!ppr)
		return;
	while (*ppr)
		free(*ppr++);
	free(y);
}

/**
 * rifai_realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *rifai_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *h;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	h = malloc(new_size);
	if (!h)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		h[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (h);
}

