#include "main.h"

/**
 * print_unsigned_num - prints an unsigned interger
 * @ap: lists args
 * @buffer: Active flags
 * @flags: Calculates the active flag
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: Num, Char printed
*/
int print_unsigned_num(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);

	num = convert_size_unsigned_int(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsigned_int(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Unsigned number in octal notation
 * @ap: Lists arguments
 * @buffer: Buffer array, handles print
 * @flags:  Active flags calculated
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Num, chars printed
 */
int print_octal(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned long int num = va_arg(ap, unsigned long int);
	unsigned long int init_num = num;
	int i = BUFF_SIZE - 2;

	UNUSED(width);

	num = convert_size_unsigned_int(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsigned_int(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Unsigned number in hexadecimal notation
 * @ap: Lists arguments
 * @buffer: Buffer array, handles print
 * @flags:  Active flags Calculated
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Num, chars printed
 */

int print_hexadecimal(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(ap, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexadecimal_upper - Unsigned number in upper hexadecimal
 * notation
 * @ap: Arguments List
 * @buffer: Buffer array, handles print
 * @flags:  Active flags Calculated
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Num, chars printed
 */

int print_hexadecimal_upper(va_list ap, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(ap, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Hexadecimal number in lower or upper
 * @ap: Arguments List
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array, handles print
 * @flags:  Active flags Calculated
 * @flag_ch: Active flags Calculated
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Num, chars printed
 */
int print_hexa(va_list ap, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned_int(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsigned_int(0, i, buffer, flags, width, precision, size));
}
