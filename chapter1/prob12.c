// Write a program that prints its input one word per line.

#include <stdio.h>

int main(void)
{
    int prev = EOF;

    for (int c; c != EOF; c = getchar()) {
        if (c == ' ' || c == '\t' || c = '\t') {
            if (prev != c) {
                putchar('\n');
            }
        } else {
            putchar(c);
        }

        prev = c;
    }

    return 0;
}
