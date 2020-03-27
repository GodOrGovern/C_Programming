/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */

#include <stdio.h>

void getLengths(int* lengths);
void draw_horizontal(int* arr, int length);
void draw_vertical(int* arr, int length);
int maxArr(int* arr, int length);

int main(void)
{
    int lengths[10] = { 0 };
    getLengths(lengths);
    draw_horizontal(lengths, 10);
    printf("\n");
    draw_vertical(lengths, 10);
    return 0;
}

void getLengths(int* lengths)
{
    int inWord, curLength = 0;

    for (int c; c != EOF; c = getchar()) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (inWord) {
                if (curLength >= 10)
                    lengths[9] += 1;
                else
                    lengths[curLength-1] += 1;
                curLength = 0;
                inWord = 0;
            }
        }
        else
            inWord = 1;

        if (inWord)
            curLength += 1;
    }
}

void draw_horizontal(int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < arr[i]; j++)
            printf("#");
        printf("\n");
    }
}

void draw_vertical(int* arr, int length)
{
    int height = maxArr(arr, length);
    for (int i = height; i > 0; i--) {
        for (int j = 0; j < length; j++) {
            if (arr[j] >= i)
                printf("#######");
            else
                printf("       ");
        }

        printf("\n");
    }
}

int maxArr(int* arr, int length)
{
    int curMax = 0;
    for (int i = 0; i < length; i++)
        if (arr[i] > curMax)
            curMax = arr[i];
    return curMax;
}
