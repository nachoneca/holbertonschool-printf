#include"main.h"
/**
 * _print_string - A function that prints a string followed by a new line.
 * @str: A pointer to the string to be printed.
 * @count: A pointer to an integer that keeps
 * track of the number of characters printed.
 *
 * This function checks if the string is NULL,
 * and if so, it prints "(null)" and updates
 * the count variable to 6 (the length of "(null)").
 * If the string is not NULL, it
 * iterates through each character in the string,
 * printing it and incrementing the count variable by 1.
 */
void _print_string(char *str, int *count)
{
	if (str == NULL)
	{
	_putchar('(');
	_putchar('n');
	_putchar('u');
	_putchar('l');
	_putchar('l');
	_putchar(')');
	*count += 6;
	}
	else
	{
		for (; *str != '\0'; str++)
		{
			_putchar(*str);
			(*count)++;
		}
	}
}
