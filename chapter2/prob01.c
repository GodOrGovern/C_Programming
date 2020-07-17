/*
 * Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("Maximum value of unsigned char: %i\n", UCHAR_MAX);
    printf("Maximum value of unsigned short: %i\n", USHRT_MAX);
    printf("Maximum value of unsigned int: %u\n", UINT_MAX);
    printf("Maximum value of unsigned long: %lu\n", ULONG_MAX);

    printf("Range of signed char: %i to %i\n", CHAR_MIN, CHAR_MAX);
    printf("Range of signed short: %i to %i\n", SHRT_MIN, SHRT_MAX);
    printf("Range of signed int: %i to %i\n", INT_MIN, INT_MAX);
    printf("Range of signed long: %li to %li\n", LONG_MIN, LONG_MAX);

    return 0;
}
