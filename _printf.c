#include "main.h"
/*
 * _printf - produces output according to a format.
 * @format: Pointer to a charstring to a constant char.
 * Return: number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
    int count = 0;
    char arg_a;
    int arg_b;
    char *arg_c;
    va_list arguments;

    va_start(arguments, format);

    for (; *format != '\0'; format++)
    {
        if (*format != '%')
        {
            putchar(*format);
            count++;
        }
        else
        {
            format++;
            if (*format == 'c')
            {
                arg_a = va_arg(arguments, int);
                putchar(arg_a);
                count++;
            }
            else if (*format == 's')
            {
                arg_c = va_arg(arguments, char *);
                if (arg_c == NULL)
                {
                    putchar('(');
                    putchar('n');
                    putchar('u');
                    putchar('l');
                    putchar('l');
                    putchar(')');
                    count += 6;
                }
                else
                    for (; *arg_c != '\0'; arg_c++)
                    {
                        putchar(*arg_c);
                        count++;
                    }
            }
            else if (*format == 'd' || *format == 'i')
            {
                arg_b = va_arg(arguments, int);
                if (arg_b < 0)
                {
                    putchar('-');
                    count++;
                    count += _printf("-d", -arg_b);
                }
                else
                {
                    if (arg_b >= 10)
                    {
                        count += _printf("d", arg_b / 10);
                    }
                    putchar(arg_b % 10 + '0');
                    count++;
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                count++;
            }
            else
            {
                putchar('%');
                putchar(*format);
                count += 2;
            }
        }
    }

    va_end(arguments);

    return (count);
}
