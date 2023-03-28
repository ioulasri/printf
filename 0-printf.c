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
	switch (c)
	{
		case 'd':
		case 'i':
			print_int(va_arg(args, int), sum);
			break;
		case 'c':
			_putchar(va_arg(args, int), sum);
			break;
		case '%':
			_putchar('%', sum);
			break;
		case 's':
			print_str(va_arg(args, char *), sum);
			break;
		case 'b':
			print_binary(va_arg(args, unsigned int), sum);
			break;
		default:
			_putchar('%', sum);
			_putchar(c, sum);
			break;
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
			handle_spec(format[i + 1], &sum, args);
			i += 2;
		}
	}

	va_end(args);
	return (sum);
}
