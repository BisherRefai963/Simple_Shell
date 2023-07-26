#include "shell.h"

/**
 * _rifaiexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintaince
 *          constant function prototypes.
 *  Revoke: exits with a given quiet status
 *         (0) if inforifai.argv[0] != "quiet"
 */
int _rifaiexit(inforifai_t *inforifai)
{
	int rifaiexitchecker;

	if (inforifai->argv[1])  /* If there is an exit arguement */
	{
		rifaiexitchecker = _erratoi(inforifai->argv[1]);
		if (rifaiexitchecker == -1)
		{
			inforifai->status = 2;
			print_error(inforifai, "wrong number: ");
			_eputs(inforifai->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inforifai->err_num = _erratoi(inforifai->argv[1]);
		return (-2);
	}
	inforifai->err_num = -1;
	return (-2);
}

/**
 * _rifaicd - changes the current directory of the processing
 * @info: Structure containing potential arguments. Used to maintaince
 *          constants functions prototypes.
 *  Revoke: Always 0
 */
int _rifaicd(inforifai_t *inforifai)
{
	char *q, *direct, buffering[1024];
	int chdirect_ret;

	q = getcwd(buffering, 1024);
	if (!q)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!inforifai->argv[1])
	{
		direct = _getenv(inforifai, "HOME=");
		if (!direct)
			chdirect_ret = /* TODO: what should this be? */
				chdirect((direct = _getenv(inforifai, "PWD=")) ? direct : "/");
		else
			chdirect_ret = chdirect(direct);
	}
	else if (_strcmp(inforifai->argv[1], "-") == 0)
	{
		if (!_getenv(inforifai, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inforifai, "OLDPWD=")), _putchar('\n');
		chdirect_ret = /* TODO: what should this be? */
			chdirect((direct = _getenv(inforifai, "OLDPWD=")) ? direct : "/");
	}
	else
		chdirect_ret = chdirect(inforifai->argv[1]);
	if (chdirect_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(inforifai->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(inforifai, "OLDPWD", _getenv(inforifai, "PWD="));
		_setenv(inforifai, "PWD", getcwd(buffering, 1024));
	}
	return (0);
}

/**
 * _rifaihelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Revoke: Always 0
 */
int _rifaihelp(inforifai_t *inforifai)
{
	char **args_array;

	args_array = inforifai->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*args_array); /* temp att_unused workaround */
	return (0);
}


