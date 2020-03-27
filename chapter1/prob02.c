/* Experiment to find out what happens when printf's argument string contains
 * \c, where c is some character not listed above */

#include <stdio.h>

int main(void)
{
    printf("Backspace: ' \b'\n");
    printf("Vertical tab: '\v'\n");
    printf("Single quote: '\''\n");
    printf("Double quote: '\"'\n");

    return 0;
}
