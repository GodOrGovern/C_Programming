/*
 * Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time
*/

#include <stdio.h>

#define MAXLINE 1000

/*
 * Summary:
 *   Reverse 'line' and store the result in 'revLine'
 * Parameters:
 *   line    (char[]): line being reversed
 *   revLine (char[]): reversed 'line'
 *   length  (int):    the number of characters in 'line' (and thus 'revLine')
 * Return Value:
 *   Doesn't return anything. (Note: 'revLine' is modified in place)
 * Description:
 *   'line' is iterated over in reverse. Each character is added to 'revLine'
 *   starting at 'revLine[0]' until the first character in 'line' is reached.
*/
void reverse(char line[], char revLine[], int length);
/*
 * Summary:
 *   Copy a line from stdin to the array 'line'
 * Parameters:
 *   line  (char[]): stores the copied characters
 *   limit (int):    maximum number of characters to be copied
 * Return Value:
 *   The number of characters in the copied line. (Note: 'line' is modified in
 *   place)
 * Description:
 *   Up to 'limit' characters are copied from stdin to the array 'line', which
 *   is modified in place. The length of the copied line is returned.
*/
int getLine(char line[], int limit);

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
