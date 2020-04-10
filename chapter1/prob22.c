/* Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column */

#include <stdio.h>

#include "helpers.h"

#define MAXLINE 1000
#define FOLD 5

/* Fold 'line' with length 'length'. The fold starts at 'line[start]'. Each
 * line is at most 'width' characters long. Folds at the last non-blank
 * character before 'line[start+width]' if it exists, otherwise folds at
 * 'line[start+width]' (or up to end of line) */
void foldLine(char line[], int length, int start, int width);

int main(void)
{
    int len = 0;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        foldLine(line, len, 0, FOLD);
    }

    return 0;
}

void foldLine(char line[], int length, int start, int width)
{
    if (length > width) {
        int blank = start + width;
        for (; blank > start && line[blank] != ' ' && line[blank] != '\t'; blank--);
        int end = blank == start ? start+width : blank+1;
        for (int i = start; i < end; i++) {
            putchar(line[i]);
        }
        putchar('\n');
        foldLine(line, length-(end-start), end, width);
    } else {
        for (int i = start; i < start+length; i++) {
            putchar(line[i]);
        }
    }
}
