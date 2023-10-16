#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * _print_char - handles the 'c' conversion specifier
 * @c: character to be printed
 * @char_print: pointer to the character count
 */

void _print_char(char c, int *char_print)
{
	write(1, &c, 1);
	(*char_print)++;
}
/**
 * _print_str - handles the 's' conversion specifier
 * @str: character to be printed
 * @char_print: pointer to the character count
 */
void _print_str(char *str, int *char_print)
{
	int len = 0;

	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
		(*char_print)++;
	}
}

/**
 * _printf - custom printf function
 * @format: string format
 * Return: the lenght of the printed string
 */

int _printf(const char *format, ...)
{
	va_list args;
	int char_print  = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format == 'c')
				_print_char(va_arg(args, int), &char_print);
			else if (*format == 's')
				_print_str(va_arg(args, char *), &char_print);
			else if (*format == '%')
				_print_char('%', &char_print);
			else if (*format == '%' && format[1] == '%')
			{
				write(1, "%%", 2);
				char_print += 2;
			}
		}

		format++;
	}
	va_end(args);

	return (char_print);
}
