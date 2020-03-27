// Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

int main(void)
{
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

    for (int c; c != EOF; c = getchar()) {
        if (c == ' ')
            blanks++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n')
            newlines++;
    }

    printf("Blanks: %i\n", blanks);
    printf("Tabs: %i\n", tabs);
    printf("Newlines: %i\n", newlines);
    return 0;
}
