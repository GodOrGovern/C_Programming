/* Write a program to print all input lines that are longer than 80 characters */

#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > 80)
            printf("%s\n", line);

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i, overflow = 0;
    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c != EOF && c != '\n')
        for (overflow = 0; (c=getchar()) != EOF && c != '\n'; overflow++);
    else if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i+overflow;
}
