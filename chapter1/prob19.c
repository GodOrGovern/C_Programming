/* Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time. */

#include <stdio.h>

#include "helpers.h"

#define MAXLINE 1000

/* Reverse the string stored in 'line' and store the result in 'revLine'.
 * 'line' has 'length' characters. It assumes that 'line[length-1] == '\n''
 * and 'line[length] == '\0'' */
void reverse(char line[], char revLine[], int length);

int main(void)
{
    int len = 0;
    char line[MAXLINE], revLine[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        reverse(line, revLine, len);
        printf("%s", revLine);
    }

    return 0;
}

void reverse(char line[], char revLine[], int length)
{
    revLine[length-1] = '\n';
    revLine[length] = '\0';
    int pos = length-2;

    for (int i = 0; i < length-1; i++) {
        revLine[pos--] = line[i];
    }
}
