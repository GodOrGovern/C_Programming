/* Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines */

#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int limit);

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
