/* Write a program to copy its input to its output, replacing each string of
 * one or more blanks by a single blank. */

#include <stdio.h>

int main(void)
{
    int prev = EOF;

    for (int c; c != EOF; c = getchar()) {
        if ((c == ' ' && prev != ' ') || c != ' ') {
            putchar(c);
        }
        prev = c;
    }

    return 0;
}
