/*
 * In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly,
 *  regardless of the machine on which it runs.
*/

/*
 * The original version of itoa cannot handle the largest negative number,
 * -2147483648 or -(2^31) because when it is made positive while recording the
 * sign (ie n = -n) the result overflows and stays at -(2^31). This means that
 * the do-while loop terminates after one loop and (n % 10), which is used as
 * an offset to '0' for finding the correct ASCII character, is negative and
 * thus does not produce the correct value.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Summary:
 *   Convert the integer 'n' to a string stored at 's[]'
 * Parameters:
 *   n (int):    number being converted to string
 *   s (char[]): array that will store string representation of 'n'
 * Return Value:
 *   Doesn't return anything. (Note: 's[]' is modified in place)
 * Description:
 *   Extracts the digits of 'n' one-by-one in reverse order and copies them
 *   into 's[]'. The sign of 'n' is recorded beforehand so '-' can be added to
 *   's[]' if necessary ('n' becomes 0 so this information cannot be extracted
 *   from it). Finally, 's[]' is reversed.
*/
void itoa(int n, char s[]);

int main(void)
{
    char s[15];
    itoa(-2147483648, s);
    puts(s);
    itoa(0, s);
    puts(s);
    itoa(2147483647, s);
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

void itoa(int n, char s[])
{
    bool negative = n < 0;
    int i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (negative) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
