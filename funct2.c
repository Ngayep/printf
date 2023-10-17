#include "main.h"

/**
 * print_unsigned_number - Print an unsigned integer.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */

int print_unsigned_number(unsigned int n)
{
	int check;
	int len;
	unsigned int num;

	check = 1;
	len = 0;

	num = n;

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
 * p_binary - prints an unsigned integer in binary format
 * @args: A va_list containing the unsigned integer to print
 * Return: The number of characters printed
 */

int p_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary[32];
	int i = 0;
	int char_print = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		binary[i] = (num % 2) + '0';
		num /= 2;
		i++;
	}

	for (i--; i >= 0; i--)
	{
		_putchar(binary[i]);
		char_print++;
	}
	return (char_print);
}

/**
 * p_hex_upper - Handle the 'X' conversion specifier.
 * @args: A va_list containing the unsigned integer to print in uppercase hex.
 *
 * Return: The number of characters printed.
 */

int p_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int len = print_hex_number(n, 1);

	return (len);
}
