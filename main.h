#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void _putchar(char c);
int _printf(const char *format, ...);
int handle_spec(char c, va_list args);
int _strlen(char *s);
void print_str(char *str);
int _num_count(int num);
void print_int(int num);

#endif
