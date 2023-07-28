#include "shell.h"

/**
 * p_free - frees a pointer and NULLs the address
 * @p: address of the pointer to free
 * Return: 1 if freed, otherwise 0.
 */

int p_free(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
