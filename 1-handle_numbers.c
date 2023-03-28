#include "main.h"

/**
 * print_int - prints a given number
 * @num: the number to be printed
 * @sum: the sum of printed characters (int numbers)
 */
void print_int(int num, int *sum, char *buffer, int *buf_pos)
{
	unsigned int tmp;

	if (num < 0)
	{
		_putchar('-', sum, buffer, buf_pos);
		tmp = num * -1;
	}
	else
	{
		tmp = num;
	}

	if (tmp < 10)
	{
		_putchar(tmp + '0', sum, buffer, buf_pos);
	}
	else
	{
		print_int((tmp / 10), sum, buffer, buf_pos);
		print_int((tmp % 10), sum, buffer, buf_pos);
	}
}

/**
 * print_binary - prints an integer in binary format
 * @num: the integer to print
 * @sum: the pointer to the integer variable that
 * keeps track of the number of characters printed
 */
void print_binary(unsigned int num, int *sum, char *buffer, int *buf_pos)
{
	if (num > 1)
	{
		print_binary(num / 2, sum, buffer, buf_pos);
	}
	_putchar(num % 2 == 0 ? '0' : '1', sum, buffer, buf_pos);
}

/**
 * print_decimal - prints an unsigned integer in decimal format
 * @num: the unsigned integer to print
 * @sum: the pointer to the integer variable
 * that keeps track of the number of characters printed
 */
void print_decimal(unsigned int num, int *sum, char *buffer, int *buf_pos)
{
	if (num >= 10)
	{
		print_decimal(num / 10, sum, buffer, buf_pos);
	}
	_putchar(num % 10 + '0', sum, buffer, buf_pos);
}

/**
 * print_hex - prints an unsigned integer in hexadecimal format
 * @num: the unsigned integer to print
 * @cap: a flag indicating whether to use capital letters (1) or not (0)
 * @sum: the pointer to the integer variable
 * that keeps track of the number of characters printed
 */
void print_hex(unsigned int num, int cap, int *sum, char *buffer, int *buf_pos)
{
	int digit;

	if (num >= 16)
	{
		print_hex(num / 16, cap, sum, buffer, buf_pos);
	}
	digit = num % 16;

	if (digit < 10)
	{
		_putchar(digit + '0', sum, buffer, buf_pos);
	}
	else
	{
		_putchar(digit - 10 + (cap ? 'A' : 'a'), sum, buffer, buf_pos);
	}
}

/**
 * print_octal - prints an unsigned integer in octal format
 * @num: the unsigned integer to print
 * @sum: the pointer to the integer variable
 * that keeps track of the number of characters printed
 */
void print_octal(unsigned int num, int *sum, char *buffer, int *buf_pos)
{
	if (num >= 8)
	{
		print_octal(num / 8, sum, buffer, buf_pos);
	}
	_putchar(num % 8 + '0', sum, buffer, buf_pos);
}
