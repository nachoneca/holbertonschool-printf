#include "main.h"

/**
* _printf - produces output according to a format.
* @format: Pointer to a charstring to a constant char.
* Return: number of characters printed
* (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
	int count = 0;
	char arg_a;
	char *arg_b;
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
				arg_b = va_arg(arguments, char *);
				if (str_arg == NULL)
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
