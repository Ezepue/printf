#include "main.h"

/**
 * print_chararcter - Prints a char
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_character(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (handle_write_character(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, a;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percentage - Prints a percent sign
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percentage(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_interger - Print int
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_interger(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int b = va_arg(args, long int);
	unsigned long int number;

	b = convert_size_number(b, size);

	if (b == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)b;

	if (b < 0)
	{
		number = (unsigned long int)((-1) * b);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[a--] = (number % 10) + '0';
		number /= 10;
	}

	a++;

	return (write_number(is_negative, a, buffer, flags, width, precision, size));
}

/**
 * print_binary_number - Prints an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary_number(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int num, a, b;
	unsigned int binary[32];
	int count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(args, unsigned int);
	a = 2147483648;
	binary[0] = num / a;

	b = 1;

	while (a < 31)
	{
		a /= 2;
		binary[b++] = (num / a) % 2;
	}
	b = 0;

	while (b < 32)
	{
		if (binary[b] || b == 31)
		{
			char z = '0' + binary[b];

			write(1, &z, 1);
			count++;
		}
		b++;
	}

	return (count);
}

