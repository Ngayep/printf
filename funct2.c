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
	int char_print = 0;
	char binary[32];
        int index = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		binary[index] = (num % 2) + '0';
		num /= 2;
		index++;
	}

	for (index--; index >= 0; index--)
	{
		_putchar(binary[index]);
		char_print++;
	}
	return char_print;
}
