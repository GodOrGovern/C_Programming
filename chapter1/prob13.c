/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */

#include <stdio.h>

#include "helpers.h"

#define MAX_LENGTH 10

void getLengths(int* lengths, int maxLength);

int main(void)
{
    int lengths[MAX_LENGTH+1] = { 0 };
    getLengths(lengths, MAX_LENGTH);

    drawHorizontal(lengths, MAX_LENGTH+1);
    drawVertical(lengths, MAX_LENGTH+1);

    return 0;
}

void getLengths(int* lengths, int maxLength)
{
    int c = EOF, inWord = 0, curLength = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (inWord) {
                if (curLength > maxLength) {
                    lengths[maxLength] += 1;
                } else {
                    lengths[curLength] += 1;
                }
                curLength = 0;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }

        if (inWord) {
            curLength += 1;
        }
    }
}
