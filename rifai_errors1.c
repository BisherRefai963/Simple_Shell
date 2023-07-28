#include "shell.h"

/**
 * rifai_erratoi - converts a string to an integer
 * @s: the string to be converted
 * Revoke: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int rifai_erratoi(char *s)
{
	int q = 0;
	unsigned long int rifai_result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (q = 0;  s[q] != '\0'; q++)
	{
		if (s[q] >= '0' && s[q] <= '9')
		{
			rifai_result *= 10;
			rifai_result += (s[q] - '0');
			if (rifai_result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rifai_result);
}

/**
 * rifai_print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void rifai_print_error(inforifai_t *inforifai, char *estr)
{
	_eputs(inforifai->fname);
	_eputs(": ");
	print_d(inforifai->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inforifai->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * rifai_print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int rifai_print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int p, counter = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		counter++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (p = 1000000000; p > 1; p /= 10)
	{
		if (_abs_ / p)
		{
			__putchar('0' + current / p);
			counter++;
		}
		current %= p;
	}
	__putchar('0' + current);
	counter++;

	return (counter);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array_rifai;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long l = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		l = -num;
		sign = '-';

	}
	array_rifai = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array_rifai[l % base];
		l /= base;
	} while (l != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * rifai_remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void rifai_remove_comments(char *buf)
{
	int k;

	for (k = 0; buf[k] != '\0'; k++)
		if (buf[k] == '#' && (!k || buf[k - 1] == ' '))
		{
			buf[k] = '\0';
			break;
		}
}

