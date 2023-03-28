#include "main.h"

/**
 * _putchar - writes a character to the standard output
 * @c: the character to write
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _print_string - prints a string to the standard output
 * @str: the string to print
 * Return: the number of characters printed
 */
int _print_string(char *str)
{
    int count = 0;

    if (str == NULL)
    {
        count += write(1, "(null)", 6);
    }
    else
    {
        while (*str)
        {
            count += _putchar(*str);
            str++;
        }
    }

    return (count);
}
