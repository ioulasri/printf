#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _strlen - returns the length of a given string
 * @s: the string
 * Return: the length of given string
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - prints a character to stdout
 * @c: the char to print
 */

void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * _num_count - counts the length of a number
 * @num: the number
 * Return: the length of the number
 */

int _num_count(int num)
{
	int count = 0;

	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

/**
 * print_number - prints a given number
 * @n: the number to be printed
 */

void print_number(int n)
{
	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		print_number(147483648);
	}
	else if (n < 0)
	{
		_putchar('-');
		n = -n;
		print_number(n);
	}
	else if (n > 9)
	{
		print_number(n / 10);
		print_number(n % 10);
	}
	else
		_putchar(n + 48);
}

/**
 * _puts - prints a given string
 * @str: the string
 */

void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * handle_format - handles given format specifiers and prints the args
 * @c: the format specifier
 * @arg: the arguments
 */

int handle_format(char c, va_list arg)
{
	if (c == 'd' || c == 'i')
	{
		int num = va_arg(arg, int);

		print_number(num);
		return (_num_count(num));
	}
	else if (c == 'c')
	{
		char e = va_arg(arg, int);

		_putchar(e);
		return (1);
	}
	else if (c == 's')
	{
		char *s = va_arg(arg, char *);
		
		_puts(s);
		return (_strlen(s));
	}

	else if (c == '%')
	{	
		_putchar('%');
	}
	return (1);
}

/**
 * _printf - prints string integer and char using format specifiers
 * @format: the first argument containing the string and format specifiers
 * Return: the length of the printed string.
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int printed_chars = 0;
	int re;
	va_list arg;

	va_start(arg, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			i++;
			printed_chars += 1;
		}
		else
		{
			re = handle_format(format[i + 1], arg);
			printed_chars += re;
			i += 2;
		}
	}

	va_end(arg);
	return (printed_chars);
}

