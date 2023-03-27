#include "main.h"

/**
 * handle_spec - handles given format specifiers and prints the args
 * @c: the format specifier
 * @args: the arguments
 * @sum: the number of characters printed
 * Return: returns the number of characters printed
 */

void handle_spec(char c, int *sum, va_list args)
{
	if (c == 'd' || c == 'i')
	{
		int num = va_arg(args, int);

		print_int(num, sum);
	}
	else if (c == 'c')
	{
		char ch = va_arg(args, int);

		sum += _putchar(ch);
	}
	else if (c == '%')
	{
		char ch = '%';

		sum += _putchar(ch);
	}
	else if (c == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			print_str("(null)", sum);
		else
			print_str(str, sum);
	}
	else
	{
		sum += _putchar(c);
	}
}

/**
 * _printf - prints string integer and char using format specifiers
 * @format: the first argument containing the string and format specifiers
 * Return: the length of the printed string.
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int sum = 0;
	va_list args;

	va_start(args, format);
	if (!format || !format[0])
		return (-1);
	while (*(format + i) && format)
	{
		if (format[i] != '%')
		{
			sum += _putchar(format[i]);
			i++;
		}
		else
		{
			handle_spec(format[i + 1], &sum, args);
			i += 2;
		}
	}
	if (!sum)
		sum = -1;
	va_end(args);
	return (sum);
}
