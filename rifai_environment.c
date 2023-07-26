#include "shell.h"

/**
 * rifai_myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Revoke: Always 0
 */
int rifai_myenv(inforifai_t *inforifai)
{
	print_list_str(inforifai->env);
	return (0);
}

/**
 * rifai_getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Revoke: the value
 */
char *rifai_getenv(inforifai_t *inforifai, const char *name)
{
	listrifai_t *node = inforifai->env;
	char *u;

	while (node)
	{
		u = starts_with(node->str, name);
		if (u && *u)
			return (u);
		node = node->next;
	}
	return (NULL);
}

/**
 *rifai _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int rifai_mysetenv(inforifai_t *inforifai)
{
	if (inforifai->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(inforifai, inforifai->argv[1], inforifai->argv[2]))
		return (0);
	return (1);
}

/**
 * rifai_myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Revoke: Always 0
 */
int rifai_myunsetenv(info_t *info)
{
	int o;

	if (inforifai->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (o = 1; o <= inforifai->argc; i++)
		_unsetenv(inforifai, inforifai->argv[o]);

	return (0);
}

/**
 * rifai_populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Revoke: Always 0
 */
int rifai_populate_env_list(inforifai_t *inforifai)
{
	listrifai_t *node = NULL;
	size_t o;

	for (i = 0; environ[o]; o++)
		add_node_end(&node, environ[o], 0);
	inforifai->env = node;
	return (0);
}

