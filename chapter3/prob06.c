/*
 * Write a version of itoa that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* Summary:
 *   Convert the integer 'n' to a string stored at 's[]' and pad the left side
 *   with spaces (if necessary) so there are at least 'minwidth' total
 *   characters.
 * Parameters:
 *   n        (int):    number being converted to string
 *   s        (char[]): array that will store string representation of 'n'
 *   minwidth (int):    minimum field width for 's[]'
 * Return Value:
 *   Doesn't return anything. (Note: 's[]' is modified in place)
 * Description:
 *   Extracts the digits of 'n' one-by-one in reverse order and copies them
 *   into 's[]'. The sign of 'n' is recorded beforehand so '-' can be added to
 *   's[]' if necessary ('n' becomes 0 so this information cannot be extracted
 *   from it). If fewer than 'minwidth' characters are used, spaces are
 *   added to 's[]' to make up the difference. Finally, 's[]' is reversed.
*/
void itoa(int n, char s[], int minwidth);

int main(void)
{
    char s[15];
    itoa(125, s, 10);
    puts(s);
    return 0;
}

/* Summary:
 *   Reverse the string stored in 's[]'
 * Parameters:
 *   s (char[]): string being copied from
 * Return Value:
 *   Doesn't return anything (Note: 's[]' is modified in place)
 * Description:
 *   Iterates through 's[]' swapping elements from the front and back until the
 *   middle is reached.
*/
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[], int minwidth)
{
    bool negative = n < 0;
    int i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (negative) {
        s[i++] = '-';
    }
    for (; i < minwidth; i++) {
        s[i] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}
