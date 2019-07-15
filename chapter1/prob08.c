// Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

int main(void)
{
    count = 0;
    for (int c; c != EOF; c = getchar())
        if (c == ' ' || c == '\t' || c == '\n')
            count += 1;
    printf("%i\n", count);
    return 0;
}
