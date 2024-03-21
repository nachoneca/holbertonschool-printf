#include "main.h"
/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success, the number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

