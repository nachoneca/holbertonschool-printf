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

/**
 * _puts - Prints a string to stdout.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */

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

    return count;
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *arg_b;

	va_start(args, format);
	if (format == NULL)
		return -1;

	for (;*format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += _putchar(va_arg(args, int));

			else if (*format == 's')
			{
				arg_b = va_arg(args, char *);
				if (arg_b == NULL)
				{
					_putchar('(');
					_putchar('n');
					_putchar('u');
					_putchar('l');
					_putchar('l');
					_putchar(')');
					count += 6;
				}
				else
				{
					for (; *arg_b != '\0'; arg_b++)
					{
						_putchar(*arg_b);
						count++;
					}
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
				count += _print_int(va_arg(args, int));

			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
	}
    	va_end(args);
	return count;
}
