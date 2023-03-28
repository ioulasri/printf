#include "main.h"

/**
 * _putchar - prints a character to stdout
 * @c: the char to print
 * @sum: the number of printed char
 */

void _putchar1(char c, int *sum)
{
	write(1, &c, 1);
	(*sum)++;
}

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

		_putchar1(ch, sum);
	}
	else if (c == '%')
	{
		char ch = '%';

		_putchar1(ch, sum);
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
		_putchar1(c, sum);
	}
}

/**
 * _printf - prints a string to stdout
 * @format: the string to print
 * Return: the number of characters printed, or -1 on error
 */

int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(args);
				return (-1);
			}
			if (format[i] != 'c' && format[i] != 's')
			{
				_putchar('%');
				count++;
				continue;
			}
			if (format[i] == 'c')
			{
				char c = (char)va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				if (!s)
					s = "(null)";
				while (*s)
				{
					_putchar(*s);
					count++;
					s++;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
