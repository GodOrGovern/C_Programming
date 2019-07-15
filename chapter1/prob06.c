// Verify that the expression getchar() != EOF is 0 or 1

#include <stdio.h>

int main(void)
{
    for (int c; c != EOF; c = getchar())
        printf("%i\n", c != EOF);
    printf("%i\n", c);
    return 0;
}
