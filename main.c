#include "main.h"

int main(void)
{
	_printf("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
    _printf("Character:[%c] [%c] [%c]\n", 'H', 'a', 'r');
    printf("Character:[%c] [%c]\n", 'H', 'a');
    _printf("String:[%s]\n", (void*)NULL);
    printf("String:[%s]\n", (void*)NULL);
	_printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");
	_printf("Print this number [%d]\n", -2147483648);
	printf("hello [%c] oh\n", '\n');
	_printf("hello [%c] oh\n", '\n');
	return (0);
}
