/*
 * Verify that the expression getchar() != EOF is 0 or 1
*/

#include <stdio.h>

int main(void)
{
    printf("Enter a character: ");
    printf("The value of \"getchar() != EOF\" is %i\n", getchar() != EOF);

    return 0;
}
