#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void _putchar(char c, int *sum)
{
    write(1, &c, 1),
    (*sum)++;
}

void print_int(int num, int *sum)
{
    static int sign;
    char c;

    if (num < 0)
    {
        write(1, "-", 1);
        (*sum)++;
        num *= -1;
    }
    else
        num *= 1;
    
    if (num < 10)
    {
        c = num + '0';
        write(1, &c, 1);
        (*sum)++;
    }
    else
    {
        print_int((num / 10), sum);
        print_int((num % 10), sum);
    }
}
void print_str(char *str, int *sum)
{
    int i = 0;

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
        (*sum)++;
    }
}
void handel_spec(char c, int * sum, va_list args)
{
    if (c == 'd' || c == 'i')
    {
        int num = va_arg(args, int);
        print_int(num, sum);
    }
    else if (c == 'c')
    {
        char c = va_arg(args, int);
        _putchar(c, sum);
    }
    else if (c == '%')
    {
        char c = '%';
        _putchar(c, sum);
    }
    else if (c == 's')
    {
        char *str = va_arg(args, char *);
        print_str(str, sum);
    }
}
int _printf(char *str, ...)
{
    int i = 0;
    int sum = 0;
    va_list args;

    va_start(args, str);
    while(*(str + i))// str[i]
    {
        if (str[i] != '%')
        {
            _putchar(str[i], &sum);
            i++;
        }
        else
        {
              handel_spec(str[i + 1], &sum, args);
              i += 2;
        }
        
    }
    va_end(args);
    return (sum);
}
