/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */

#include <stdio.h>

#define MAX_LENGTH 10

void getLengths(int* lengths, int maxLength);
void drawHorizontal(int* arr, int length);
void drawVertical(int* arr, int length);
int maxArr(int* arr, int length);

int main(void)
{
    int lengths[MAX_LENGTH+1] = { 0 };
    getLengths(lengths, MAX_LENGTH);

    printf("\n");
    drawHorizontal(lengths, MAX_LENGTH+1);

    printf("\n");
    drawVertical(lengths, MAX_LENGTH+1);

    return 0;
}

void getLengths(int* lengths, int maxLength)
{
    int c;
    int inWord = 0;
    int curLength = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (inWord) {
                if (curLength > maxLength)
                    lengths[maxLength] += 1;
                else
                    lengths[curLength] += 1;
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

void drawHorizontal(int* arr, int arrSize)
{
    for (int i = 1; i < arrSize; i++) {
        if (i == arrSize - 1)
            printf(">%i|", i-1);
        else
            printf("%2i|", i);

        for (int j = 0; j < arr[i]; j++)
            printf("#");
        printf("\n");
    }
}

void drawVertical(int* arr, int arrSize)
{
    int maxHeight = maxArr(arr, arrSize);
    for (int i = maxHeight; i > 0; i--) {
        for (int j = 0; j < arrSize; j++) {
            if (arr[j] >= i)
                printf("#");
            else
                printf(" ");
            printf("  ");
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
