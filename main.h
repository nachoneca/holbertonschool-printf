#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int _printf(const char *format, ...);

/*
 *_print_string - to print str
 *@str: string to print
 *@count: contador
 */
void _print_string(char *str, int *count);
/*
 *@format_char: char given
 *@count: contador
 */
void _print_char_and_format(char format_char, int *count);

/**
 * _print_int - Prints an integer.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int _print_int(long int n);

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success, the number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c);
#endif
