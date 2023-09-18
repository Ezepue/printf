#include "main.h"
/**
 * handle_print - Prints an argument based on its type.
 * @format: Formatted string, prints the arguments.
 * @args: List of arguments to be printed.
 * @a: index
 * @buffer: Buffer array, handles print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *format, int *a, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, untold_lenght = 0, char_count = -1;
	fmt_t format_types[] = {
		{'c', print_character}, {'s', print_string}, {'%', print_percentage},
		{'i', print_interger}, {'d', print_interger}, {'b', print_binary_number},
		{'u', print_unsigned_num}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexadecimal_upper}, {'p', print_pt}, {'S', print_nonprint},
		{'r', print_reverse}, {'R', print_str_rot13}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*a] == format_types[i].format)
			return (format_types[i].fn(args, buffer, flags, width, precision, size));

	if (format_types[i].format == '\0')
	{
		if (format[*a] == '\0')
			return (-1);
		untold_lenght += write(1, "%%", 1);
		if (format[*a - 1] == ' ')
			untold_lenght += write(1, " ", 1);
		else if (width)
		{
			--(*a);
			while (format[*a] != ' ' && format[*a] != '%')
				--(*a);
			if (format[*a] == ' ')
				--(*a);
			return (1);
		}
		untold_lenght += write(1, &format[*a], 1);
		return (untold_lenght);
	}
	return (char_count);
}
