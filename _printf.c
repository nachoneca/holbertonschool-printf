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

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
		    {
		    arg_b = va_arg(args, char *);
                                if (arg_b == NULL)
                                {
                                        printf("(null)");
                                        count += 6;
                                }
                                else
                                        for (; *arg_b != '\0'; arg_b++)
                                        {
                                                putchar(*arg_b);
                                                count++;
                                        }

		    }
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                case 'd':
                case 'i':
                    count += _print_int(va_arg(args, int));
                    break;
                default:
                    count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);

    return count;
}
