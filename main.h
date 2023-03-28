#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c, int *sum, char *buffer, int *buf_pos);
void handle_spec(char c, int *sum, va_list args, char *buffer, int *buf_pos);
int _strlen(char *s);
void print_str(char *str, int (*sum), char *buffer, int *buf_pos);
int _num_count(int num);
void print_int(int num, int *sum, char *buffer, int *buf_pos);
void print_binary(unsigned int num, int *sum, char *buffer, int *buf_pos);
void print_octal(unsigned int num, int *sum, char *buffer, int *buf_pos);
void print_hex(unsigned int num, int cap, int *sum, char *buffer, int *buf_pos);
void print_decimal(unsigned int num, int *sum, char *buffer, int *buf_pos);

#endif
