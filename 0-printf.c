#include "main.h"

/**
 * _printf - prints formatted output to the standard output stream
 * @format: the format string
 * Return: the number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            if (*format == '%')
            {
                count += _putchar('%');
            }
            else if (*format == 'c')
            {
                char c = va_arg(args, int);
                count += _putchar(c);
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                count += _print_string(s);
            }
            else
            {
                count += _putchar('%');
                count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return (count);
}
