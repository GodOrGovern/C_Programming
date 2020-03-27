/* Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time. */

#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int limit);

int main(void)
{
    char line[MAXLINE];

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
