/* Write a program to print all input lines that are longer than 80 characters */

#include <stdio.h>

#include "helpers.h"

#define MAXLINE 1000
#define MINLENGTH 80

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > MINLENGTH) {
            printf("%s\n", line);
        }
    }

    return 0;
}
