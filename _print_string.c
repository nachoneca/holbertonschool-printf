#include"main.h"
/*
 *_print_string - to print str
 *@str: string to print
 *@count: contador
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
        for (; *str != '\0'; str++) {
            _putchar(*str);
            (*count)++;
        }
    }
}
