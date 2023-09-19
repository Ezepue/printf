#include "main.h"

/**
 * handle_write_char - Prints string
 * @c: char types.
 * @buffer: Buffer, handles print
 * @flags:  Active flags calculator.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Num, chars printed.
 */
int handle_write_character(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored onthe lef sidet and paddind at buffer's right */
	int a = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';

	buffer[a++] = c;
	buffer[a] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buffer[BUFF_SIZE - a - 2] = pad;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints string
 * @is_negative: Arguments list
 * @idx: char types.
 * @buffer: Buffer array, handles print
 * @flags:  Active flags calculator
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Num, chars printed.
 */

int write_number(int is_negative, int idx, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - idx - 1;
	char pad = ' ', extra_chr = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (is_negative)
		extra_chr = '-';
	else if (flags & F_PLUS)
		extra_chr = '+';
	else if (flags & F_SPACE)
		extra_chr = ' ';

	return (write_num(idx, buffer, flags, width, precision,
		length, pad, extra_chr));
}

/**
 * write_num - Number written using bufffer
 * @idx: Index where the number begins on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @exact: Precision specifier
 * @length: Number length
 * @pad: Padding char
 * @extra_chr: Extra char
 * Return: Num, printed chars.
 */
int write_num(int idx, char buffer[],
	int flags, int width, int exact,
	int length, char pad, char extra_chr)
{
	int a, pad_start = 1;

	if (exact == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0' && width == 0)
		return (0);
	if (exact == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0')
		buffer[idx] = pad = ' ';
	if (exact > 0 && exact < length)
		pad = ' ';
	while (exact > length)
		buffer[--idx] = '0', length++;
	if (extra_chr != 0)
		length++;
	if (width > length)
	{
		for (a = 1; a < width - length + 1; a++)
			buffer[a] = pad;
		buffer[a] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (extra_chr)
				buffer[--idx] = extra_chr;
			return (write(1, &buffer[idx], length) + write(1, &buffer[1], a - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (extra_chr)
				buffer[--idx] = extra_chr;
			return (write(1, &buffer[1], a - 1) + write(1, &buffer[idx], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_chr)
				buffer[--pad_start] = extra_chr;
			return (write(1, &buffer[pad_start], a - pad_start) +
				write(1, &buffer[idx], length - (1 - pad_start)));
		}
	}
	if (extra_chr)
		buffer[--idx] = extra_chr;
	return (write(1, &buffer[idx], length));
}

/**
 * write_unsigned_int - Writes unsigned number
 * @is_negative: Indicates if num is negative
 * @idx: Index where number begins in the buffer
 * @buffer: Array, chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Num, written chars.
 */
int write_unsigned_int(int is_negative, int idx,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* number stored on bufer's right, beginning at position i */
	int length = BUFF_SIZE - idx - 1, a = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		pad = ' ';

	while (precision > length)
	{
		buffer[--idx] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';

	if (width > length)
	{
		for (a = 0; a < width - length; a++)
			buffer[a] = pad;

		buffer[a] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[idx], length) + write(1, &buffer[0], a));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[idx], length));
		}
	}

	return (write(1, &buffer[idx], length));
}

/**
 * write_ptr - Writes memory address
 * @buffer: Arrays, chars
 * @idx: Index where number begins in the buffer
 * @length: Length of num
 * @width: Width specifier
 * @flags: Flags specifier
 * @pad: Char, represnts the padding
 * @extra_chr: Char, represents extra char
 * @pad_start: Index, beginning of padding
 * Return: Numb, written chars.
 */

int write_ptr(char buffer[], int idx, int length,
	int width, int flags, char pad, char extra_chr, int pad_start)
{
	int a;

	if (width > length)
	{
		for (a = 3; a < width - length + 3; a++)
			buffer[a] = pad;
		buffer[a] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--idx] = 'x';
			buffer[--idx] = '0';
			if (extra_chr)
				buffer[--idx] = extra_chr;
			return (write(1, &buffer[idx], length) + write(1, &buffer[3], a - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--idx] = 'x';
			buffer[--idx] = '0';
			if (extra_chr)
				buffer[--idx] = extra_chr;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[idx], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_chr)
				buffer[--pad_start] = extra_chr;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], a - pad_start) +
				write(1, &buffer[idx], length - (1 - pad_start) - 2));
		}
	}
	buffer[--idx] = 'x';
	buffer[--idx] = '0';
	if (extra_chr)
		buffer[--idx] = extra_chr;
	return (write(1, &buffer[idx], BUFF_SIZE - idx - 1));
}
