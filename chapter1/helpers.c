#include <stdio.h>
#include "helpers.h"

int getLine(char line[], int limit)
{
    int c, i = 0;
    for (i = 0; i < limit-1 && (c=getchar())!=EOF && c!='\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
    }
    line[++i] = '\0';
    return i;
}

void drawHorizontal(int* arr, int length)
{
    printf("\n");
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < arr[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void drawVertical(int* arr, int length)
{
    printf("\n");
    int height = maxArr(arr, length);
    for (int i = height; i > 0; i--) {
        for (int j = 0; j < length; j++) {
            if (arr[j] >= i) {
                printf("#");
            } else {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
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
