#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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
	int i = 0;
	int printed_chars = 0;
	int re;
	va_list arg;

	va_start(arg, format);
	if (format)
	{
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
	}

	va_end(arg);
	return (printed_chars);
}

int main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}
