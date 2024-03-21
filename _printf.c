#include "main.h"
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
		return (-1);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				return (-1);
			}
			if (*format == 'c')
				count += _putchar(va_arg(args, int));
			else if (*format == 's')
			{
				arg_b = va_arg(args, char *);
				_print_string(arg_b, &count);
			}
			else if (*format == '%')
			{
				count += _putchar('%');
			}
			else if (*format == 'd' || *format == 'i')
				count += _print_int(va_arg(args, int));
			else
				_print_char_and_format(*format, &count);
		}
		else
		{
			count += _putchar(*format);
		}
	}
	va_end(args);
	return (count);
}
