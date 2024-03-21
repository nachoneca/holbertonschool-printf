#include"main.h"
void _print_char_and_format(char format_char, int *count) {
    _putchar('%');
    _putchar(format_char);
    (*count) += 2;
}
