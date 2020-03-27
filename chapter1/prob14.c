/* Write a program to print a histogram of the frequencies of different
 * characters in its input. */

#include <stdio.h>
#include <ctype.h>

void getCounts(int* counts);
void histogram(int* arr, int length);
int maxArr(int* arr, int length);

int main(void)
{
    /* Keeps track of four categories of input: letters, numbers, whitespace,
     * and other (which is everything else) */
    int counts[4] = { 0 };
    getCounts(counts);
    histogram(counts, 4);
    return 0;
}

void getCounts(int* counts)
{
    for (int c; c != EOF; c = getchar()) {
        if (isalpha(c))
            counts[0] += 1;
        else if (isdigit(c))
            counts[1] += 1;
        else if (c == ' ' || c == '\n' || c == '\t')
            counts[2] += 1;
        else
            counts[3] += 1;
    }
}

void histogram(int* arr, int length)
{
    int height = maxArr(arr, length);
    for (int i = height; i > 0; i--) {
        for (int j = 0; j < length; j++) {
            if (arr[j] >= i)
                printf("#");
            else
                printf(" ");
            printf(" ");
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
