#include "main.h"

void print_buffer(char *buffer, int *buff_index);
/**
 * _printf - Printf Function
 * @format: Format
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int a, count = 0, char_count = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_index++] = format[a];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			char_count++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &a);
			width = get_width(format, &a, args);
			precision = get_precision(format, &a, args);
			size = get_size(format, &a);
			a++;
			count = handle_print(format, &a, args, buffer,
					flags, width, precision, size);
			if (count == -1)
				return (-1);
			char_count += count;
		}
	}

	print_buffer(buffer, &buff_index);
	va_end(args);

	return (char_count);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}
