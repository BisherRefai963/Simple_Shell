#include "shell.h"

/**
* n_words - number of words in string
* @s: input
* Return: number of words
*/

int n_words(char *s)
{
	int i, n;

	n = 0;
	for (i = 0; s[i]; i++)
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] != '\0' && s[i + 1] != ' ')
				n++;
		}
		else if (i == 0)
			n++;
	}
	n++;
	return (n);
}


/**
* strtow - splits a string into words.
* @str: input
* Return: pointer to an array of strings (words)
*/

char **strtow(char *str)
{
	int i, j, k, n = 0, count = 0;
	char **words;

	if (*str == '\0' || str == NULL)
		return (NULL);
	n = n_words(str);
	if (n == 1)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * n);
	if (words == NULL)
		return (NULL);
	words[n - 1] = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
				;
			j++;
			words[count] = (char *)malloc(sizeof(char) * j);
			j--;
			if (words[count] == NULL)
			{
				for (k = 0; k < count; k++)
					free(words[k]);
				free(words[n - 1]);
				free(words);
				return (NULL);
			}
			for (k = 0; k < j; k++)
				words[count][k] = str[i + k];
			words[count][k] = '\0';
			count++;
			i += j;
		}
		else
			i++;
	}
	return (words);
}
