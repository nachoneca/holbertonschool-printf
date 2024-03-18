#include "main.h"

/**
* _printf - produces output according to a format.
* @format: Pointer to a charstring to a constant char.
* Return: number of characters printed
* (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
	int divisor = 1;
	int count = 0;
	char arg_a;
	char *arg_b;
	int arg_c;
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
			if (*format == '\0')
			{
				;
			}
			else if (*format == 'c')
			{
				arg_a = va_arg(arguments, int);
				putchar(arg_a);
				count++;
			}
			else if (*format == 's')
			{
				arg_b = va_arg(arguments, char *);
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
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				arg_c = va_arg(arguments, int);
				 if (arg_c < 0) {
        putchar('-');
        count++;
        arg_c = -arg_c;
    }
    
   
    while (arg_c / divisor >= 10) {
        divisor *= 10;
    }
 
    while (divisor != 0) {
        putchar('0' + arg_c / divisor);
        count++;
        arg_c %= divisor;
        divisor /= 10;
    }

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
