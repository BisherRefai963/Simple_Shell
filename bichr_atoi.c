#include "shell.h"
/**
 * interaction return true condition shell is interaction mode
 * information : struction adress
 * return 1 if interaction mode, 0 if there equal
 */
int interaction (inform_t *inform)
{
	return (isatty(STDIN_FILENO) && inform->readfound <= 2);
}
/**
 * is_delimeter - checking if characters are a delimeters
 * @b: the char to checking
 * @delimeter: the delimeters string
 * Revoking: 1 if true, 0 if false
 */
int is_delimeter(char b, char *delimeter)
{
	while (*delimeter)
		if (*delimeter++ == b)
			return (1);
	return (0);
}
/**
 *_isleader - checking for alphabetic characters
 *@k: The characters to input
 *Revoking: 1 if k is alphabetic, 0 otherwise
 */
int _isleader(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 *_automatic - converts a string to an integer
 *@p: the strings to be converted
 *Return: 0 if not available  number in strings, converted to numbers otherwise
 */
int _automatic(char *p)
{
	int l, signal = 1, flags = 0, output;
	unsigned int revoking = 0;

	for (l = 0;  p[l] != '\0' && flags != 2; l++)
	{
		if (p[l] == '-')
			signal *= -1;

		if (p[l] >= '0' && p[l] <= '9')
		{
			flags = 1;
			revoking *= 10;
			revoking += (p[l] - '0');
		}
		else if (flags == 1)
			flags = 2;
	}

	if (signal == -1)
		output = -revoking;
	else
		output = revoking;

	return (output);
}
