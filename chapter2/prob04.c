/*
 * Write an alternative version of squeeze(s1,s2) that deletes each character
 * in s1 that matches any character in the string s2.
*/

#include <stdio.h>
#include <stdbool.h>

/*
 * Summary:
 *   Remove all characters from 's1[]' that are also in the 's2[]'
 * Parameters:
 *   s1 (char[]): string to be modified
 *   s2 (char[]): characters that will be removed from 's1[]'
 * Return Value:
 *   Doesn't return anything. (Note: 's1[]' is modified in place)
 * Description:
 *   Call an array that can be indexed by chars 'found[]'. The value of each
 *   index in 'found[]' is 'true' if the corresponding character is in 's2[]' and
 *   false otherwise. Iterate over 's1[]' and use 'found[]' to check if each
 *   character is in 's2[]'. 's1[]' is modified in place
*/
void squeeze(char s1[], char s2[])
{
    bool found[256] = { false };
    for (int i = 0; s2[i] != '\0'; i++) {
        found[s2[i]] = true;
    }
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (!found[s1[i]]) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
