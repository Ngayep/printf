#include "main.h"
#include <stdarg.h>

/**
 * _printf -my own printf function
 * @format: string format
 */

int _printf(const char *format, ...)
{
	int char_print = 0;

	va_list args;

	if(format == NULL)
		return (-1);

	va_start(args, format);

while (*format != '%')
	{
		write(1, format, 1);
	} else
	{
		format++; 
	}

	va_arg(args, format);

	va_end;
}
