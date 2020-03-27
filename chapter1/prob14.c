/* Write a program to print a histogram of the frequencies of different
 * characters in its input. */

#include <stdio.h>
#include <ctype.h>

#include "helpers.h"

#define CATEGORIES

void getCounts(int* counts);

int main(void)
{
    /* Keeps track of four categories of input: letters, numbers, whitespace,
     * and other (which is everything else) */
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
        } else
            counts[3] += 1;
        }
    }
}
