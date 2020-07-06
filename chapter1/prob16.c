/*
 * Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrarily long input lines, and as much as possible of
 * the text
*/

#include <stdio.h>

#define MAXLINE 1000

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
/*
 * Summary:
 *   Copy the characters in 'from' to 'to'
 * Parameters:
 *   from (char[]): characters being copied
 *   to   (char[]): copy of 'from'
 * Return Value:
 *   Doesn't return anything. (Note: 'to' is modified in place)
 * Description:
 *   'from[]' is iterated over from start to end. Each character is copied to
 *   the corresponding index in 'to'
*/
void copy(char from[], char to[]);

int main(void)
{
    int len = 0, max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }
    putchar('\n');
    if (max > 0) {
        puts(longest);
        printf("%i\n", max);
    }

    return 0;
}

int getLine(char line[], int limit)
{
    int c, i, overflow = 0;
    for (i = 0; i < limit-1 && (c=getchar())!=EOF && c!='\n'; i++) {
        line[i] = c;
    }
    if (c != EOF && c != '\n') {
        for (overflow = 0; (c=getchar())!=EOF && c!='\n'; overflow++);
    } else if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i+overflow;
}

void copy(char from[], char to[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
