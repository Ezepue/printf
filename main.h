#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unstd.h>

#define BUFF_SIZE 1024
#define UNUSED (x) (void) (x)

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1


/* Funtions to print chars and strings */
int print_char(va_list ap, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list ap, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list ap, char buffer[],
	int flags, int width, int precision, int size);



int _printf(const char *format, ...);

#endif
