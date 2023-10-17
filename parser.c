#include "main.h"

/**
 * parser - Parse a format string and
 * call appropriate functions for conversion specifiers.
 * @format: The format string to parse.
 * @_functlist: An array of conversion specifier symbols and
 * their corresponding functions.
 * @args: A va_list containing the arguments.
 *
 * This function iterates through the format string and,
 * when it encounters '%',
 * checks for a matching conversion specifier in the funct_list.
 * If a match is found,
 * it calls the corresponding function
 * with the arguments from va_list. If no match is
 * found, it prints '%' and the next character as-is.
 * The function returns the number
 * of characters printed.
 *
 * Return: The number of characters printed. Returns -1 on error.
 */

int parser(const char *format, _convert _functlist[], va_list args)
{
	int i, j, r_val, char_print = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; _functlist[j].sym != NULL; j++)
			{
				if (format[i + 1] == _functlist[j].sym[0])
				{
					r_val = _functlist[j].f(args);
					if (r_val == -1)
						return (-1);
					char_print += r_val;
					break;
				}
			}
			if (_functlist[j].sym == NULL && format[i + j] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			char_print++;
		}
	}
	return (char_print);
}
