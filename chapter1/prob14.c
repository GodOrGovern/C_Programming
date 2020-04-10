/* Write a program to print a histogram of the frequencies of different
 * characters in its input. */

#include <stdio.h>
#include <ctype.h>

#include "helpers.h"

#define CATEGORIES 4

/* Store the frequencies of various kinds of inputs in 'counts'.
 * The 0th element is for letters, 1st for numbers, 2nd for whitespace, and 3rd
 * for everything else */
void getCounts(int* counts);

int main(void)
{
    int counts[CATEGORIES] = { 0 };
    getCounts(counts);

    drawHorizontal(counts, CATEGORIES);
    drawVertical(counts, CATEGORIES);

    return 0;
}

void getCounts(int* counts)
{
    for (int c; c != EOF; c = getchar()) {
        if (isalpha(c)) {
            counts[0] += 1;
        } else if (isdigit(c)) {
            counts[1] += 1;
        } else if (c == ' ' || c == '\n' || c == '\t') {
            counts[2] += 1;
        } else {
            counts[3] += 1;
        }
    }
}
