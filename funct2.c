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
