#include "main.h"
#include <stdarg.h>

/**
 * handle_format - handles given format specifiers and prints the args
 * @c: the format specifier
 * @arg: the arguments
 * Return: returns the number of characters printed
 */

int handle_format(char c, va_list arg)
{
	if (c == 'c')
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
