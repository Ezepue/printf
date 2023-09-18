##Printf Function

###Description

This team project is a custom made printf function for the C programming language called _printf. It has been optimized to take various inputs and optional arguments based exactly on how the standard library function printf works.All the files are to be compiled on Ubuntu 14.04 LTS. Compiled with gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

**The available convertion specifiers are:**

%c: Prints a single character.
%s: Prints a string of characters.
%d: Prints integers.
%i: Prints integers.
%b: Prints the binary representation of an unsigned decimal.
%u: Prints unsigned integers
%x: Prints the hexadecial representation of an unsigned decimal in lowercase letters
%X:Prints the hexadecial representation of an unsigned decimal in uppercase letters
%r: Prints a reversed string
%R: Prints the Rot13 interpretation of a string


>#include "main.h"
#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0
 *
/
int main(void)
{
    int a;
    int b;
    unsigned int x;
    void *addr;

    a = _printf("Let's try to printf a simple sentence.\n");
    b = printf("Let's try to printf a simple sentence.\n");
    x = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", a, a);
    printf("Length:[%d, %i]\n", b, b);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", x);
    printf("Unsigned:[%u]\n", x);
    _printf("Unsigned octal:[%o]\n", x);
    printf("Unsigned octal:[%o]\n", x);
    _printf("Unsigned hexadecimal:[%x, %X]\n", x, x);
    printf("Unsigned hexadecimal:[%x, %X]\n", x, x);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    return (0);
}


