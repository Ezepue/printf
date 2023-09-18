#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @fn: The function associated.
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @format: The format.
 * @fm_t: The function associated.
 */
typedef struct format fmt_t;


int _printf(const char *format, ...);
int handle_print(const char *format, int *a,
va_list args, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int print_character(va_list args, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_percentage(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_interger(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary_number(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned_num(va_list ap, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list ap, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list ap, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal_upper(va_list ap, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list ap, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


/* Funcion to print memory address */
int print_pt(va_list ap, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print non printable characters */
int print_nonprint(va_list ap, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print string in reverse*/
int print_reverse(va_list ap, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_str_rot13(va_list ap, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *a);
int get_width(const char *format, int *a, va_list ap);
int get_precision(const char *format, int *a, va_list ap);
int get_size(const char *format, int *a);




/* width handler */
int handle_write_character(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int idx, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int idx, char buffer[], int flags, int width, int exact,
	int length, char pad, char extra_chr);
int write_ptr(char buffer[], int idx, int length,
	int width, int flags, char pad, char extra_chr, int pad_start);
int write_unsigned_int(int is_negative, int idx,
	char buffer[], int flags, int width, int precision, int size);

/* Utils */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned_int(unsigned long int num, int size);

#endif
