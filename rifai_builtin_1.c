#include "shell.h"

/**
 * _rifaihistory - display  history of the lists, one command by line, proceeded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Revoke: Always 0
 */
int _rifaihistory(inforifai_t *inforifai)
{
	print_list(inforifai->rifaihistory);
	return (0);
}

/**
 * rifai_unset_alias - sets alias to string
 * @info: parameter structs
 * @str: the string aliases
 *
 * Revoke: Always 0 on success, 1 on error
 */
int rifai_unset_alias(inforifai_t *inforifai, char *str)
{
	char *a, b;
	int retier;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	retier = delete_node_at_index(&(inforifai->alias),
		get_node_index(inforifai->alias, node_starts_with(inforifai->alias, str, -1)));
	*a = b;
	return (retier);
}

/**
 * rifai_set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Revoke: Always 0 on success, 1 on error
 */
int rifai_set_alias(inforifai_t *inforifai, char *str)
{
	char *a;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (rifai_unset_alias(inforifai, str));

	rifai_unset_alias(inforifai, str);
	return (add_node_end(&(inforifai->alias), str, 0) == NULL);
}

/**
 * rifai_print_alias - prints an alias string
 * @node: the alias node
 *
 * Revoke: Always 0 on success, 1 on error
 */
int rifai_print_alias(listrifai_t *node)
{
	char *a = NULL, *c = NULL;

	if (node)
	{
		a = _strchr(node->str, '=');
		for (c = node->str; c <= a; c++)
			_putchar(*c);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _rifaimyalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _rifaimyalias(inforifai_t *inforifai)
{
	int k = 0;
	char *a = NULL;
	listrifai_t *node = NULL;

	if (inforifai->argc == 1)
	{
		node = inforifai->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (k = 1; inforifai->argv[k]; k++)
	{
		p = _strchr(inforifai->argv[k], '=');
		if (a)
			set_alias(inforifai, inforifai->argv[k]);
		else
			print_alias(node_starts_with(inforifai->alias, inforifai->argv[k], '='));
	}

	return (0);
}

