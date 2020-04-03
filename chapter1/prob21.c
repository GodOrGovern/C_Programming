/* Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as
 * for detab. */

/* Question: When either a tab or a single blank would suffice to reach a tab
 * stop, which should be given preference?
 * Answer: A blank should be given preference as tabs do not have a uniform
 * width. */

#include <stdio.h>

#define TABSIZE 8

int main()
{
    int c = EOF, spaces = 0, pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces += 1;
        } else if (c == '\n' || c == '\t') {
            spaces = pos = 0;
            putchar(c);
        } else {
            if (spaces > 0) {

            }
            putchar(c);
        }

        prev = c;
    }

    return 0;
}
