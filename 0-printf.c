#include "main.h"

/**
 * handle_format - handles given format specifiers and prints the args
 * @c: the format specifier
 * @arg: the arguments
 * Return: returns the number of characters printed
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
	else
	{
		_putchar(c);
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
	va_list args;
	int count;

	count = 0;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				print_char(args, &count);
			else if (*format == 's')
				print_string(args, &count);
			else if (*format == '%')
				print_percent(&count);
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
