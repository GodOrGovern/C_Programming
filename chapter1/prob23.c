/*
 * Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments don't
 * nest.
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    for (int c; c != EOF; c = getchar()) {
        if (c == '/') {
            c = getchar();
            if (c == '/') {
                for (; c != '\n'; c = getchar());
                putchar(c);
            } else if (c == '*') {
                for (; c != EOF; c = getchar()) {
                    if (c == '*' && (c = getchar()) == '/') {
                        break;
                    }
                }
            } else {
                putchar('/');
                putchar(c);
            }
        } else if (c == '\'' || c == '\"') {
            putchar(c);
            for (int close = c; c != close; c = getchar()) {
                putchar(c);
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
