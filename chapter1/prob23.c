/*
 * Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments don't
 * nest.
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int close = EOF;
    bool inQuote = false, possComm = false;

    for (int c; c != EOF; c = getchar()) {
        if (possComm && c != '/' && c != '*') {
            putchar('/');
            possComm = false;
        }
        if (c == '\'' || c == '\"') {
            if (inQuote) {
                inQuote = c != close;
            } else {
                inQuote = true;
                close = c;
            }
        } else if (c == '/' && !inQuote) {
            if (possComm) {
                for (; c != '\n'; c = getchar());
            }
            possComm = !possComm;
        } else if (c == '*' && !inQuote && possComm) {
            c = getchar();
            for (; c != EOF; c = getchar()) {
                if (c == '*' && (c = getchar()) == '/') {
                    break;
                }
            }
            c = getchar();
            possComm = false;
        } else if (c == '\\' && inQuote) {
            bool evenNum = false;
            putchar(c);
            c = getchar();
            for (; c == '\\'; c = getchar()) {
                putchar(c);
                evenNum = !evenNum;
            }
            inQuote = !(c == close && evenNum);
        }

        if (!possComm) {
            putchar(c);
        }
    }

    return 0;
}
