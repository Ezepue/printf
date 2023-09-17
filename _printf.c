#include "main.h"

void print_buffer(char *buffer, int *buff_ind);

/**
 * _printf - Printf Function
 * @format: Format
 * Return: the number of characters printed 
 */

int _printf(const char *format, ...)
{
	int i, count = 0, char_count = 0;
	int flags, width, precision, size, buff_ind = 0;

	va_list args;
	char *buff;

	buff = malloc(BUFF_SIZE * sizeof(char));
	if(buff == NULL)
		return (-1);

	va_start(args, format);
	
	for(i = 0; format && format[1] != '\0', i++)
	{
		if(format[1] != '%')
		{
			buffer[buff_ind++] = format[1];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			char_count++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i, args, buffer);
			i++;
			count = handle_print(format, &i, args, buffer
					flags, width, precision, size);
			if(count == -1)
				return (-1);
			char_count += count;
		}
	}
	
	print_buffer(buffer, &buff_ind);

	va_end(args);

	free(buff);
	
	return (char_count);

}

/**

 * print_buffer - Prints the contents of the buffer if it exist 
 * buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char *buffer, int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

    *buff_ind = 0;
}       
