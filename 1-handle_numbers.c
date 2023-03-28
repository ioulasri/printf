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
 * print_binary - prints binary value of param.
 *
 * @num: The integer to print in binary form.
 * @sum: A pointer to an integer variable
 * that keeps track of the total
 * number of characters printed so far.
 */

void print_binary(int num, int *sum)
{
	char buffer[50];
	int i = 0;

	if (num < 0)
	{
		_putchar('-', sum);
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0', sum);
		return;
	}

	while (num > 0)
	{
		buffer[i++] = num % 2 + '0';
		num /= 2;
	}

	while (--i >= 0)
	{
		_putchar(buffer[i], sum);
	}
}
