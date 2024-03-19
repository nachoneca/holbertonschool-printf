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
int _puts(char *str)
{
    int count = 0;

    if (str == NULL)
    {
   	    putchar('(');
	 putchar('n');
	 putchar('u');
	 putchar('l');
	 putchar('l');
	 putchar(')');
	 count += 6;
	 return count;
	}

    else 
    {
        for (; *str != '\0'; str++)
	{
		putchar(*str);
		count++;
       }
    }

    count += _putchar('\n');

    return count;
}

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
                    count += _puts(va_arg(args, char *));
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
