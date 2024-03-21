#include"main.h"
/*
*_print_char_and_format - print cgar and format.
*@format_char: char given
*@count: contador
*/
void _print_char_and_format(char format_char, int *count)
{
	_putchar('%');
	_putchar(format_char);
	(*count) += 2;
}
