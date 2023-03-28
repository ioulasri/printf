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
 * _putchar - writes a character to the output stream
 * @c: the character to write
 * @sum: the pointer to the integer variable that
 * keeps track of the number of characters printed
 * @buffer: the local buffer to use for output
 * @buf_pos: the pointer to the integer variable
 * that keeps track of the current position in the buffer
 *
 * Return: On success, the character written is
 * returned. On error, -1 is returned.
 */
int _putchar(char c, int *sum, char *buffer, int *buf_pos)
{
    if (*buf_pos == BUFFER_SIZE)
    {
        write(STDOUT_FILENO, buffer, BUFFER_SIZE);
        *buf_pos = 0;
    }
    buffer[*buf_pos] = c;
    (*buf_pos)++;
    (*sum)++;
    return (c);
}

/**
 * print_str - prints a given string
 * @str: the string
 * @sum: the sum of printed characters
 */

void print_str(char *str, int (*sum), char *buffer, int *buf_pos)
{
	int i = 0;

	while (str && str[i])
	{
		_putchar(str[i], sum, buffer, buf_pos);
		i++;

		if (*buf_pos == BUFFER_SIZE)
		{
			write(STDOUT_FILENO, buffer, BUFFER_SIZE);
			*sum += BUFFER_SIZE;
			*buf_pos = 0;
		}
	}
}
