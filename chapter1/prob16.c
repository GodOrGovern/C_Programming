/* Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrarily long input lines, and as much as possible of
 * the text. */

#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    printf("\n");
    if (max > 0) {
        printf("%s\n", longest);
        printf("%i\n", max);
    }
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

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        i++;
}
