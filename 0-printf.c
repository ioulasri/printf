#include "main.h"

/**
 * handle_spec - handles given format specifiers and prints the args
 * @c: the format specifier
 * @args: the arguments
 * @sum: the number of characters printed
 * Return: returns the number of characters printed
 */

void handle_spec(char c, int *sum, va_list args, char *buffer, int *buf_pos)
{
	switch (c)
	{
		case 'd':
		case 'i':
			print_int(va_arg(args, int), sum, buffer, buf_pos);
			break;
		case 'c':
			_putchar(va_arg(args, int), sum, buffer, buf_pos);
			break;
		case '%':
			_putchar('%', sum, buffer, buf_pos);
			break;
		case 's':
			print_str(va_arg(args, char *), sum, buffer, buf_pos);
			break;
		case 'b':
			print_binary(va_arg(args, unsigned int), sum, buffer, buf_pos);
			break;
		case 'u':
			print_decimal(va_arg(args, unsigned int), sum, buffer, buf_pos);
			break;
		case 'o':
			print_octal(va_arg(args, unsigned int), sum, buffer, buf_pos);
			break;
		case 'x':
			print_hex(va_arg(args, unsigned int), 0, sum, buffer, buf_pos);
			break;
		case 'X':
			print_hex(va_arg(args, unsigned int), 1, sum, buffer, buf_pos);
			break;
		default:
			_putchar('%', sum, buffer, buf_pos);
			_putchar(c, sum, buffer, buf_pos);
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
	int i = 0, sum = 0, buf_pos = 0;
	char buffer[BUFFER_SIZE];
	va_list args;

	if (!format || !format[0])
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i], &sum, buffer, &buf_pos);
			i++;
		}
		else if (format[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		else
		{
			handle_spec(format[i + 1], &sum, args, buffer, &buf_pos);
			i += 2;
		}

		if (buf_pos == BUFFER_SIZE)
		{
			write(STDOUT_FILENO, buffer, BUFFER_SIZE);
			sum += BUFFER_SIZE;
			buf_pos = 0;
		}
	}

	if (buf_pos > 0)
	{
		write(STDOUT_FILENO, buffer, buf_pos);
		sum += buf_pos;
	}

	va_end(args);
	return (sum);
}
