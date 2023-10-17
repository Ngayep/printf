#include "main.h"

/**
 * p_unsigned - Handle the 'u' conversion specifier.
 * @args: A va_list containing the unsigned integer to print.
 *
 * Return: The number of characters printed.
 */

int p_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int len = printunsigned_number(n);
}

/**
 * print_octal_number - Print an unsigned integer in octal format.
 * @args: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_octal_number(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		int octalDigit = n % 8;

		_putchar('0' + octalDigit);
		n /= 8;
		count++;
	}
	return (count);
}

/**
 * p_octal - Handle the 'o' conversion specifier.
 * @args: A va_list containing the unsigned integer to print in octal.
 *
 * Return: The number of characters printed.
 */
int p_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int len = print_octal_number(n);

	return (len);
}

/**
 * print_hex_number - Print an unsigned integer in hexadecimal format.
 * @args: A va_list containing the integer to print.
 * @uppercase: A flag indicating whether to print uppercase hex digits.
 *
 * Return: The number of characters printed.
 */

int print_hex_number(va_list args, bool uppercase)
{
	unsigned int n = va_arg(args, unsigned int);
	char hexDigits[] = "0123456789abcdef";

	int count = 0;
	char hex[32];

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		int hexDgit = n % 16;

		hex[count] = (uppercase ? toupper(hexDigits[hexDgit]) : hexDigits[hexDgit]);
		n /= 16;
		count++;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		_putchar(hex[i]);
	}
	return (count);
}

/**
 * p_hex - Handle the 'x' conversion specifier.
 * @args: A va_list containing the unsigned integer to print in lowercase hex.
 *
 * Return: The number of characters printed.
 */

int p_hex(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int len = print_hex_number(n, 0);

	return (len);
}
