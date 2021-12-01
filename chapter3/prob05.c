/*
 * Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16)
 * formats s as a hexadecimal integer in s.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Summary:
 *   Store the string representation of the integer 'n' in base 'b' at 's[]'
 * Parameters:
 *   n (int):    number being converted to string
 *   s (char[]): array that will store string representation of 'n' in base 'b'
 *   b (int):    base to represent 'n' in
 * Return Value:
 *   Doesn't return anything. (Note: 's[]' is modified in place)
 * Description:
 *   Extracts the digits of 'n' as they would appear in base 'b' one-by-one in
 *   reverse order and copies them into 's[]'. The sign of 'n' is recorded
 *   beforehand so '-' can be added to 's[]' if necessary ('n' becomes 0 so
 *   this information cannot be extracted from it). Finally, 's[]' is reversed.
 *   Only supports bases 2-16, though more could easily be added by expanding
 *   'digits[]'.
*/
void itob(int n, char s[], int b);

int main(void)
{
    char s[10];
    itob(256, s, 16);
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

void itob(int n, char s[], int b)
{
    char* digits = "0123456789ABCDEF";
    bool negative = n < 0;
    int i = 0;
    do {
        s[i++] = digits[abs(n % b)];
    } while ((n /= b) != 0);
    if (negative) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
