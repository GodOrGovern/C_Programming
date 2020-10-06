/*
 * Write a function expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for
 * letters of either case and digits, and be prepared to handle cases like
 * a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally.
*/

/* Summary:
 *   Copy 's1[]' to 's2[]', expanding shorthand notations (eg 'a-z')
 * Parameters:
 *   s1 (char[]): string being copied from
 *   s2 (char[]): string being copied to
 * Return Value:
 *   Doesn't return anything (Note: 's2[]' is modified in place)
 * Description:
 *   Iterate through each character in 's1[]' and copy it to 's2[]'. When a '-'
 *   char is encountered, iterate through all values between the characters to
 *   the right and left unless either is a space, in which case it is printed
 *   literally.
 *   The program assumes that provided shorthand notations are valid (ie start
 *   is lower than stop and both are of same type and case)
*/
void expand(char s1[], char s2[])
{
    int i1 = 0, i2 = 0;
    for (; s1[i1] != '\0'; i1++) {
        if (s1[i1] == '-' && i1 != 0) {
            if (isspace(s1[i1-1]) || isspace(s1[i1+1])) {
                s2[i2++] = s1[i1];
                continue;
            }
            for (int j = s1[i1-1] + 1; j <= s1[i1+1]; j++) {
                s2[i2++] = j;
            }
            i1++;
        } else {
            s2[i2++] = s1[i1];
        }
    }
    s2[i2] = '\0';
}
