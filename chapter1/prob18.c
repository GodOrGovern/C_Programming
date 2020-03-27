/* Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines */

#include <stdio.h>

#include "helpers.h"

#define MAXLINE 1000

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        while (line[len-1] == ' ' || line[len-1] == '\t' || line[len-1] == '\n') {
            len--;
        }
        line[len] = '\0';
        printf("%s\n", line);
    }

    return 0;
}
