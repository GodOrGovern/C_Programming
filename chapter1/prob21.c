/* Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as
 * for detab. */

/* Question: When either a tab or a single blank would suffice to reach a tab
 * stop, which should be given preference?
 * Answer: A blank should be given preference as tabs do not have a uniform
 * size */

#include <stdio.h>

#define TABSIZE 8

int main()
{
    /* c = current character, spaces = number of current spaces in a row,
     * enter = the position of the first space in a sequence of spaces,
     * pos = current position (reset at tabs and newlines) */
    int c = EOF, spaces = 0, enter = 0, pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (spaces == 0) {
                enter = pos;
            }
            spaces++;
        } else {
            // Always print a single space over a tab
            if (spaces == 1) {
                putchar(' ');
            }
            else if (spaces > 1) {
                // Print a tab if the spaces extend beyond the next tabstop
                int remain = TABSIZE - (enter % TABSIZE);
                if (spaces > remain) {
                    putchar('\t');
                    spaces -= remain;
                }
                // Print tabs as long as there are ample spaces
                while (spaces >= TABSIZE) {
                    putchar('\t');
                    spaces -= TABSIZE;
                }
                // Print whatever spaces remain
                for (; spaces > 0; spaces--) {
                    putchar(' ');
                }
            }

            spaces = 0;
            putchar(c);
        }

        pos++;

        if (c == '\n' || c == '\t') {
            pos = 0;
        }
    }

    return 0;
}
