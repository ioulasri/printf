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
	_printf("me binary value of (123) is %b\n", 123);
	len = _printf("String:[%%%%] ok %d\n", 43);
	printf("%d\n", len);
	len = printf("String:[%%%%] ok %d\n", 32);
	_printf("%d\n", len);
	_printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");
	len = _printf("Print this number [%d]\n", -214748648);
	printf("%d\n", len);
	len = printf("Print this number [%d]\n", -214748648);
	printf("%d\n", len);
	printf("hello [%c] oh\n", '\n');
	_printf("hello [%c] oh\n", '\n');
	return (0);
}
