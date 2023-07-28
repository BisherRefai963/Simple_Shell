#include "shell.h"

/**
 * rifai_get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **rifai_get_environ(info_t *info)
{
	if (!inforifai->environ || inforifai->env_changed)
	{
		inforifai->environ = list_to_strings(inforifai->env);
		inforifai->env_changed = 0;
	}

	return (inforifai->environ);
}

/**
 * rifai_unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Revoke: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int rifai_unsetenv(inforifai_t *inforifai, char *var)
{
	list_t *node = inforifai->env;
	size_t q = 0;
	char *o;

	if (!node || !var)
		return (0);

	while (node)
	{
		o = starts_with(node->str, var);
		if (o && *o == '=')
		{
			info->env_changed = delete_node_at_index(&(inforifai->env), q);
			q = 0;
			node = inforifai->env;
			continue;
		}
		node = node->next;
		q++;
	}
	return (inforifai->env_changed);
}

/**
 * rifai_setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Revoke: Always 0
 */
int rifai_setenv(inforifai_t *inforifai, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *o;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = inforifai->env;
	while (node)
	{
		o = starts_with(node->str, var);
		if (o && *o == '=')
		{
			free(node->str);
			node->str = buf;
			inforifai->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(inforifai->env), buf, 0);
	free(buf);
	inforifai->env_changed = 1;
	return (0);
}

