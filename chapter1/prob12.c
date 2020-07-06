/*
 * Write a program that prints its input one word per line.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int prev = EOF;

    for (int c; c != EOF; c = getchar()) {
        if (isspace(c)) {
            if (!isspace(prev)) {
                putchar('\n');
            }
        } else {
            putchar(c);
        }

        prev = c;
    }

    return 0;
}
