/*
 * Experiment to find out what happens when printf's argument string contains
 * \c, where c is some character not listed above
*/

#include <stdio.h>

int main(void)
{
    puts("Backspace: ' \b'");
    puts("Vertical tab: '\v'");
    puts("Single quote: '\''");
    puts("Double quote: '\"'");

    return 0;
}
