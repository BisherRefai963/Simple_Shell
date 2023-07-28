#include "shell.h"

/**
 * rifai_main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int rifai_main(int acr, char **avr)
{
	inforifai_t inforifai[] = { INFO_INIT };
	int fdr = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fdr)
		: "r" (fdr));

	if (acr == 2)
	{
		fdr = open(avr[1], O_RDONLY);
		if (fdr == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inforifai->readfd = fdr;
	}
	populate_env_list(inforifai);
	read_history(inforifai);
	hsh(inforifai, avr);
	return (EXIT_SUCCESS);
}

