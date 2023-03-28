#include "main.h"

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	int len;

	_printf("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
	_printf("Character:[%c]\n", "%z");
	printf("Character:[%c]\n", '%');
	len = _printf("%b\n", 98);
	printf("%d\n", len);
	printf("%d\n", len);
	_printf("%d\n", len);
	_printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");
	printf("hello [%c] oh\n", '\n');
	_printf("hello [%c] oh\n", '\n');
	return (0);
}
