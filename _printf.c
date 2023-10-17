#include "main.h"

/**
 * _printf - Custom printf function that formats and prints text.
 * @format: The format string containing conversion specifiers.
 * @...: Variable arguments that correspond to the conversion specifiers.
 *
 * This function implements a custom version of printf. It accepts a format
 * string and variable arguments, and it processes the format string to print
 * the formatted text to the standard output. It supports the 'c', 's', and
 * '%%' conversion specifiers and additional specifiers for signed and unsigned
 * integers.
 *
 * Return: The number of characters printed. Returns -1 on error.
 */

int _printf(const char *format, ...)
{
	int char_print;

	_convert _functlist[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{"b", p_binary},
		{"u", p_unsigned},
		{"o", print_octal_number},
		{"x", print_hex_number},
		{"X", print_hex_number},
		{NULL, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	char_print = parser(format, _functlist, args);

	va_end(args);

	return (char_print);
}
