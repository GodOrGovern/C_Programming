// Write a program that prints its input one word per line.

#include <stdio.h>

int main(void)
{
    for (int c; c != EOF; c = getchar()) {
        if (c == ' ' || c == '\t') {
            for (; c == ' ' || c == '\t'; c = getchar());
            printf("\n");
        }
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
