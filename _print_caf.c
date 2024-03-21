#include"main.h"

/**
 * _print_char_and_format - This function prints a
 * character that represents the format specifier
 * and the format character itself, while also
 * incrementing the count by 2.
 * @format_char: The character that represents the format specifier.
 * @count: A pointer to an integer that stores the count of characters
 * printed.
 */
void _print_char_and_format(char format_char, int *count)
{
	_putchar('%');
	_putchar(format_char);
	(*count) += 2;
}
