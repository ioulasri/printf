#include "main.h"
#define INT_MIN (-2147483647 - 1)


/**
 * _num_count - counts the length of a number
 * @num: the number
 * Return: the length of the number
 */

int _num_count(int num)
{
	int count = 0;

	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

/**
 * print_int - prints a given number
 * @num: the number to be printed
 * @sum: the sum of printed characters (int numbers)
 */
void print_int(int num, int *sum)
{
	char c;
	unsigned int tmp;

	if (num == INT_MIN)
	{
		print_str("-2147483648", sum);
		return;
	}

	if (num < 0)
	{
		write(1, "-", 1);
		(*sum)++;
		tmp = (unsigned int) -num;
	} else
	{
		tmp = (unsigned int) num;
	}

	if (tmp < 10)
	{
		c = tmp + '0';
		write(1, &c, 1);
		(*sum)++;
	} else
	{
		print_int(tmp / 10, sum);
		print_int(tmp % 10, sum);
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
	int bits[32];
	int i = 0;

	if (num < 0)
	{
		putchar('-');
		num = -num;
		(*sum)++;
	}

	do {
		bits[i++] = num % 2;
		num /= 2;
	} while (num > 0);

	while (--i >= 0)
	{
		putchar(bits[i] + '0');
		(*sum)++;
	}
}
