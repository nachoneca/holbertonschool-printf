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
	int arg_c;
	int longitud;
	char *array_n;
	va_list arguments;
	int i;

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
				longitud = snprintf(NULL, 0, "%d", arg_c);
				array_n = (char *)malloc((longitud + 2) * sizeof(char));
				if (array_n != NULL)
				{
					if (arg_c < 0) 
					{
						array_n[0] = '-';
						arg_c = -arg_c;
					}
					else
					{	
					snprintf(array_n, longitud + 1, "%d", arg_c);
					for (i = 0; i < longitud; i++)
					{
						putchar(array_n[i]);
						count++;
					}
					}
				free(array_n);
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
