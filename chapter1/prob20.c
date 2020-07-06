/*
 * Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop
*/

/*
 * Question: Assume a fixed set of tab stops, say every n columns. Should n be a variable
 *   or a symbolic parameter?
 * Answer: It should probably be a variable so it can be changed at runtime
 *   without re-compiling (eg through a command line argument)
*/

#include <stdio.h>

#define TABSIZE 8

int main()
{
    int c = EOF, pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0; i < (TABSIZE - (pos % TABSIZE)); i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
            pos++;
        }

        if (c == '\n' || c == '\t') {
            pos = 0;
        }
    }

    return 0;
}
