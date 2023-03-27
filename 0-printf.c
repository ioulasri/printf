#include "main.h"

/**
 * handle_spec - handles given format specifiers and prints the args
 * @c: the format specifier
 * @args: the arguments
 * @sum: the number of characters printed
 * Return: returns the number of characters printed
 */

int handle_spec(char c, va_list args)
{
	if (c == 'd' || c == 'i')
	{
		int num = va_arg(args, int);

		print_int(num);
		return(_num_count(num));
	}
	else if (c == 'c')
	{
		char ch = va_arg(args, int);

		_putchar(ch);
		return (1);
	}
	else if (c == '%')
	{
		char ch = '%';

		_putchar(ch);
		return (1);
	}
	else if (c == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			print_str("(null)");
		else
			print_str(str);
		return (_strlen(str));
	}
	else
	{
		_putchar(c);
		return (1);
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
	int printed_chars = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL || args == NULL)
		return (-1);
	while (*(format + i) && format)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars += 1;
			i++;
		}
		else
		{
			printed_chars += handle_spec(format[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	return (printed_chars);
}
