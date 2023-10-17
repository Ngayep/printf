#include "main.h"

/**
 * print_number - Print a signed integer.
 * @args: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */

int print_number(va_list args)
{
	int a;
	int check;
	int len;
	unsigned int num;

	a = va_arg(args, int);
	check = 1;
	len = 0;

	if (a < 0)
	{
		len += _putchar('-');
		num = a * -1;
	}
	else
		num = a;

	for (; num / check > 9; )
		check *= 10;

	for (; check != 0; )
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}
	return (len);
}
/**
 * p_char - Print a character.
 * @args: A va_list containing the character to print.
 *
 * Return: The number of characters printed (always 1).
 */

int p_char(va_list args)
{
	char value;

	value = va_arg(args, int);
	_putchar(value);
	return (1);
}

/**
 * p_string - Print a string.
 * @args: A va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */

int p_string(va_list args)
{
	int i;
	const char *s;

	s = va_arg(args, const char *);

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);

	return (i);
}

/**
 * p_percent - Print a '%' character.
 * @args: A va_list (not used in this case).
 *
 * Return: The number of characters printed (always 1).
 */

int p_percent(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}

/**
 * p_integer - Print an integer.
 * @args: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */

int p_integer(va_list args)
{
	int n;

	n = print_number(args);
	return (n);
}
