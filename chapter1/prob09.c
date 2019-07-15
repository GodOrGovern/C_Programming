/* Write a program to copy its input to its output, replacing each string of
 * one or more blanks by a single blank. */

#include <stdio.h>

int main(void)
{
    for (int c; c != EOF; c = getchar()) {
        if (c == ' ') {
            for (; c == ' '; c = getchar());
            printf(" ");
        }
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
