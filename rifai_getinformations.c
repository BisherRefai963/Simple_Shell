#include "shell.h"

/**
 * rifai_clear_info - initializes info_t struct
 * @info: struct address
 */
void rifai_clear_info(inforifai_t *inforifai)
{
	inforifai->args = NULL;
	inforifai->argv = NULL;
	inforifai->path = NULL;
	inforifai->argc = 0;
}

/**
 * rifai_set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void rifai_set_info(inforifai_t *inforifai, char **av)
{
	int f = 0;

	inforifai->fname = av[0];
	if (inforifai->args)
	{
		inforifai->argv = strtow(inforifai->args, " \t");
		if (!inforifai->argv)
		{

			inforifai->argv = malloc(sizeof(char *) * 2);
			if (inforifai->argv)
			{
				inforifai->argv[0] = _strdup(inforifai->arg);
				inforifai->argv[1] = NULL;
			}
		}
		for (f = 0; inforifai->argv && inforifai->argv[f]; f++)
			;
		inforifai->argc = f;

		replace_alias(inforifai);
		replace_vars(inforifai);
	}
}

/**
 * rifai_free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void rifai_free_info(inforifai_t *inforifai, int all)
{
	ffree(inforifai->argv);
	inforifai->argv = NULL;
	inforifai->path = NULL;
	if (all)
	{
		if (!inforifai->cmd_buf)
			free(inforifai->arg);
		if (inforifai->env)
			free_list(&(inforifai->env));
		if (inforifai->history)
			free_list(&(inforifai->history));
		if (inforifai->alias)
			free_list(&(inforifai->alias));
		ffree(inforifai->environ);
			inforifai->environ = NULL;
		bfree((void **)inforifai->cmd_buf);
		if (inforifai->readfd > 2)
			close(inforifai->readfd);
		_putchar(BUF_FLUSH);
	}
}

