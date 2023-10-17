#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * struct convert - Defines a structure for conversion specifiers.
 * @sym: The conversion specifier symbol (e.g., 'c', 's', etc.).
 * @f: The function pointer for handling the specifier.
 */

typedef struct convert
{
	char *sym;
	int (*f)(va_list);
} _convert;

int _putchar(char c);
int _printf(const char *format, ...);
int parser(const char *format, _convert _functlist[], va_list args);
int p_char(va_list);
int p_string(va_list args);
int p_percent(va_list);
int print_unsigned_number(unsigned int n);
int print_number(va_list);
int p_integer(va_list);
int p_binary(va_list args);
int p_hex(va_list args);
int p_hex_upper(va_list args);
int print_octal_number(va_list args);
int print_hex_number(va_list args, bool uppercase);
int p_unsigned(va_list args);
int p_octal(va_list args);



#endif
