/*
 * Write a loop equivalent to the for loop above without using && or ||.
*/

#include <stdio.h>

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
int getLine(char s[], int limit)
{
    int c, i;
    while (i < limit-1) {
        c = getchar();
        if (c == EOF) {
            break;
        } else if (c == '\n') {
            break;
        }
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
