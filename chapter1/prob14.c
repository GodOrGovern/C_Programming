/*
 * Write a program to print a histogram of the frequencies of different
 * characters in its input
*/

#include <stdio.h>
#include <ctype.h>

#define CATEGORIES 4

/*
 * Store the frequencies of various kinds of inputs in 'counts'.
 * The 0th element is for letters, 1st for numbers, 2nd for whitespace, and 3rd
 * for everything else
*/
void getCounts(int* counts);
void drawHorizontal(int* arr, int length);
void drawVertical(int* arr, int length);
int maxArr(int* arr, int length);

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
        } else if (isspace(c)) {
            counts[2] += 1;
        } else {
            counts[3] += 1;
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
