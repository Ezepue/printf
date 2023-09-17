#include "main.h"

/**
 * print_char - Prints a char
 * @lists: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_char(char *buffer, int flags, int width,, int precision, int size, va_list lists)
{
	char c = (char)va_arg(lists, int);
	return (handle_write_char(c, buffer, flags, width, precision, size))
}

/**

 * print_string - Prints a string
 * @types: List a of arguments
 * @lists: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_string(char *buffer, int flags, int width, int precision, int size, va_list lists)
{
	h
}
