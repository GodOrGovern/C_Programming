/*
 * Write the function any(s1,s2), which returns the first location in a string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2. (The standard library function strpbrk does the same
 * job but returns a pointer to the location.)
*/

#include <stdio.h>
#include <stdbool.h>

/*
 * Summary:
 *   Return the location of the first character in 's1[]' that is also in
 *   's2[]'. If there is none return -1
 * Parameters:
 *   s1 (char[]): string to be searched for matching character
 *   s2 (char[]): characters that 's1[]' is compared against
 * Return Value:
 *   Returns the location of the first character in 's1[]' that is also in
 *   's2[]' or -1 if none exists
 * Description:
 *   Call an array that can be indexed by chars 'found[]'. The value of each
 *   index in 'found[]' is 'true' if the corresponding character is in 's2[]' and
 *   false otherwise. Iterate over 's1[]' and use 'found[]' to check if each
 *   character is in 's2[]'. If one is found, return it's location. Otherwise
 *   return -1
*/
int any(char s1[], char s2[])
{
    bool found[256] = { false };
    for (int i = 0; s2[i] != '\0'; i++) {
        found[s2[i]] = true;
    }
    for (int i = 0; s1[i] != '\0'; i++) {
        if (found[s1[i]]) {
            return i;
        }
    }
    return -1;
}
