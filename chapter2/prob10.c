/*
 * Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
*/

/*
 * Summary:
 *   Convert upper case letters to lower case
 * Parameters:
 *   c (int): letter converted to lower case
 * Return Value:
 *   Lower case version of 'c'
 * Description:
 *   Uses a ternary operator to return the lower case version of 'c' if it is
 *   upper case and if not it just returns 'c'
*/
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
