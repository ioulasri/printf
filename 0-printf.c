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

		_putchar(ch, sum);
	}
	else if (c == '%')
	{
		char ch = '%';

		_putchar(ch, sum);
	}
	else if (c == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			print_str("(null)", sum);
		else
			print_str(str, sum);
	}
	else if (c == 'b')
	{
		int num = va_arg(args, int);

		print_binary(num, sum);
	}
	else
	{
		_putchar(c, sum);
	}
}

/**
 * _printf - prints string integer and char using format specifiers
 * @format: the first argument containing the string and format specifiers
 * Return: the length of the printed string or -1 on failure.
 */

int _printf(const char *format, ...)
{
	int i = 0, sum = 0;
	va_list args;

	if (!format || !format[0])
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i], &sum);
			i++;
		}
		else if (format[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%', &sum);
				i += 2;
				continue;
			}

			handle_spec(format[i + 1], &sum, args);
			i += 2;
		}
	}

	va_end(args);
	return (sum);
}
