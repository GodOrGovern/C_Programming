/*
 * Write a program to print all input lines that are longer than 80 characters
*/

#include <stdio.h>

#define MAXLINE 1000
#define MINLENGTH 80

/*
 * Summary:
 *   Copy a line from stdin to the array 'line[]'
 * Parameters:
 *   line  (char[]): stores the copied characters
 *   limit (int):    maximum number of characters to be copied
 * Return Value:
 *   The number of characters in the copied line. (Note: 'line[]' is modified in
 *   place)
 * Description:
 *   Up to 'limit' characters are copied from stdin to the array 'line[]', which
 *   is modified in place. The length of the copied line is returned.
*/
int getLine(char line[], int limit);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > MINLENGTH) {
            puts(line);
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
