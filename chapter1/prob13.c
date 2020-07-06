/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 10

/* Each index of 'lengths' contains the number of words with length equal to
 * the value of the index. Every word longer than or equal to 'maxLength' is
 * counted in the last index of 'lengths' */
void getLengths(int* lengths, int maxLength);
void drawHorizontal(int* arr, int length);
void drawVertical(int* arr, int length);
int maxArr(int* arr, int length);

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
        if (isspace(c)) {
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

void drawHorizontal(int* arr, int length)
{
    printf("\n");
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < arr[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}

void drawVertical(int* arr, int length)
{
    putchar('\n');
    int height = maxArr(arr, length);
    for (int i = height; i > 0; i--) {
        for (int j = 0; j < length; j++) {
            if (arr[j] >= i) {
                putchar('#');
            } else {
                putchar(' ');
            }
            putchar(' ');
        }
        putchar('\n');
    }
}

int maxArr(int* arr, int length)
{
    int curMax = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > curMax) {
            curMax = arr[i];
        }
    }
    return curMax;
}
