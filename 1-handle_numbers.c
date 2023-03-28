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
		tmp = num;
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
