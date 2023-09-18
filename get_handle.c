#include "main.h"

/**
 * get_flags - Active flags Calculated
 * @format: Formatted string, arguments printed here
 * @a: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *a)
{
	int b, current_idx;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	current_idx = *a + 1;
	while (format[current_idx] != '\0')
	{
		for (b = 0; FLAGS_CH[b] != '\0'; b++)
			if (format[current_idx] == FLAGS_CH[b])
			{
				flags |= FLAGS_ARR[b];
				break;
			}

		if (FLAGS_CH[b] == 0)
			break;
	}

	*a = current_idx - 1;

	return (flags);
}

/**
 * get_size - Calculates size in which argument is casted
 * @format: Formatted string, arguments printed here
 * @a: Arguments List to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *a)
{
	int current_idx = *a + 1;
	int size = 0;

	if (format[current_idx] == 'l')
		size = S_LONG;
	else if (format[current_idx] == 'h')
		size = S_SHORT;

	if (size == 0)
		*a = current_idx - 1;
	else
		*a = current_idx;

	return (size);
}

/**
 * get_width - Width claculated for printing
 * @format: Formatted string, arguments printed here
 * @a: Arguments List to be printed.
 * @ap: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *a, va_list ap)
{
	int current_idx;
	int width = 0;

	for (current_idx = *a + 1; format[current_idx] != '\0'; current_idx++)
	{
		if (is_digit(format[current_idx]))
		{
			width *= 10;
			width += format[current_idx] - '0';
		}
		else if (format[current_idx] == '*')
		{
			current_idx++;
			width = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	*a = current_idx - 1;

	return (width);
}

/**
 * get_precision - Precision calculator for printing
 * @format: Formatted string in which to print the arguments
 * @a: Arguments list to be printed.
 * @ap: list of arguments.
 * Return: Precision.
 */

int get_precision(const char *format, int *a, va_list ap)
{
	int current_idx = *a + 1;
	int precision = -1;

	if (format[current_idx] != '.')
		return (precision);

	precision = 0;
	current_idx += 1;

	while (format[current_idx] != '\0')
	{
		if (is_digit(format[current_idx]))
		{
			precision *= 10;
			precision += format[current_idx] - '0';
		}
		else if (format[current_idx] == '*')
		{
			current_idx++;
			precision = va_arg(ap, int);
			break;
		}
		else
			break;

		current_idx++;
	}

	*a = current_idx - 1;

	return (precision);
}
