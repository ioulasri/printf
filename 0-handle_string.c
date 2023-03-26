#include "main.h"

/**
 * _strlen - returns the length of a given string
 * @s: the string
 * Return: the length of given string
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - prints a character to stdout
 * @c: the char to print
 */

void _putchar(char c)
{
    write(1, &c, 1);
}

/**
 * _puts - prints a given string
 * @str: the string
 */

void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

void print_char(va_list args, int *count)
{
    char c = (char) va_arg(args, int);

    putchar(c);
    (*count)++;
}

/**
 * print_string - prints a given string
 * @args: the string
 * @count: the len of the word
 */


void print_string(va_list args, int *count)
{
    char *s = va_arg(args, char *);

    while (*s != '\0') {
        putchar(*s);
        s++;
        (*count)++;
    }
}

void print_percent(int *count)
{
    putchar('%');
    (*count)++;
}
