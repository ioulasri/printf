#include "main.h"

/**
 * print_int - prints a given number
 * @num: the number to be printed
 * @sum: the sum of printed characters (int numbers)
 */
void print_int(int num, int *sum)
{
	char c;
	unsigned int tmp;

	if (num < 0)
	{
		write(1, "-", 1);
		(*sum)++;
		tmp = num * -1;
	}
	else
	{
		tmp = num
	}

	if (tmp < 10)
	{
		c = tmp + '0';
		write(1, &c, 1);
		(*sum)++;
	}
	else
	{
		print_int((tmp / 10), sum);
		print_int((tmp % 10), sum);
	}
}

/**
 * print_binary - prints an integer in binary format
 * @num: the integer to print
 * @sum: the pointer to the integer variable that
 * keeps track of the number of characters printed
 */
void print_binary(unsigned int num, int *sum)
{
	if (num > 1)
	{
		print_binary(num / 2, sum);
	}
	_putchar(num % 2 == 0 ? '0' : '1', sum);
}

/**
 * print_decimal - prints an unsigned integer in decimal format
 * @num: the unsigned integer to print
 * @sum: the pointer to the integer variable
 * that keeps track of the number of characters printed
 */
void print_decimal(unsigned int num, int *sum)
{
	if (num >= 10)
	{
		print_decimal(num / 10, sum);
	}
	_putchar(num % 10 + '0', sum);
}

/**
 * print_hex - prints an unsigned integer in hexadecimal format
 * @num: the unsigned integer to print
 * @cap: a flag indicating whether to use capital letters (1) or not (0)
 * @sum: the pointer to the integer variable
 * that keeps track of the number of characters printed
 */
void print_hex(unsigned int num, int cap, int *sum)
{
	int digit;

	if (num >= 16)
	{
		print_hex(num / 16, cap, sum);
	}
	digit = num % 16;

	if (digit < 10)
	{
		_putchar(digit + '0', sum);
	}
	else
	{
		_putchar(digit - 10 + (cap ? 'A' : 'a'), sum);
	}
}

/**
 * print_octal - prints an unsigned integer in octal format
 * @num: the unsigned integer to print
 * @sum: the pointer to the integer variable
 * that keeps track of the number of characters printed
 */
void print_octal(unsigned int num, int *sum)
{
	if (num >= 8)
	{
		print_octal(num / 8, sum);
	}
	_putchar(num % 8 + '0', sum);
}
