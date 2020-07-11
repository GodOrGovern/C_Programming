/*
 * Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
#include <string.h>

/*
 * Summary:
 *   Converts a hexadecimal string to decimal
 * Parameters:
 *   hex (char[]): string of hexadecimal digits
 * Return Value:
 *   Value of 'hex[]' in decimal (int)
 * Description:
 *   Iterate through 'hex', each time multiplying the value of the current
 *   hexadecimal digit by 16^position (starts at one less than the number of
 *   hex digits and is decremented by 1 each iteration) and adding the result
 *   to the running total, At the end this total is returned
*/
int htoi(char hex[])
{
    int val = 0;
    int start = (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) * 2;
    int mult = 1 << (4 * (strlen(hex) - start - 1));
    for (int i = start; hex[i] != '\0'; i++) {
        char cur = hex[i];
        if ('0' <= cur && cur <= '9') {
            val += mult * (cur - '0');
        } else if ('A' <= cur && cur <= 'F') {
            val += mult * (cur - 'A' + 10);
        } else if ('a' <= cur && cur <= 'f') {
            val += mult * (cur - 'a' + 10);
        }
        mult >>= 4;
    }

    return val;
}
