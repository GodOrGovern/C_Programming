/* Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\. This makes tabs and
 * backspaces visible in an unambiguous way. */

#include <stdio.h>

int main(void)
{
    for (int c; c != EOF; c = getchar()) {
        switch (c) {
            case '\t':
                printf("\\t");
                break;
            case '\b':
                printf("\\b");
                break;
            case '\\':
                printf("%c%c", '\\', '\\');
                break;
            default:
                printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}
