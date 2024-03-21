#include"main.h"
/**
 * _print_int - Prints an integer.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int _print_int(long int n)
{
	int count = 0;

	if (n < 0)
	{
	count += _putchar('-');
	n = -n;
	}
	if (n / 10 != 0)
		count += _print_int(n / 10);
	count += _putchar(n % 10 + '0');
	return (count);
}
