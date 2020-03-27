/* Write a program to print all input lines that are longer than 80 characters */

#include <stdio.h>

#define MAXLINE 1000
#define MINLENGTH 80

int getLine(char line[], int limit);

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

int getLine(char line[], int limit)
{
    int c, i = 0;
    for (i = 0; i < limit-1 && (c=getchar())!=EOF && c!='\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
    }
    line[++i] = '\0';
    return i;
}
