/*
 * Write a program to print a histogram of the frequencies of different
 * characters in its input
*/

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define CATEGORIES 4

/*
 * Summary:
 *   Store the lengths of words in an array where the index is the length. The
 *   last index counts all lengths greater than or equal to its index
 * Parameters:
 *   lengths   (int[]): tracks the lengths of words
 *   maxLength (int):   all lengths greater than or equal to this value are tracked by
 *                        the last index
 * Return Value:
 *   Doesn't return anything. (Note: 'lengths' is modified in place)
 * Description:
 *   Reads characters from stdin. Call the length of the current word
 *   'curLength'. When whitespace is encountered 'lengths[curLength]' is
 *   incremented by 1. If 'curLength' is greater than 'maxLength',
 *   'lengths[maxLength]' is incremented by 1. Adjacent blanks are not counted
 *   in 'lengths[]'
*/
void getLengths(int* lengths, int maxLength);
/*
 * Summary:
 *   Prints a horizontal histogram using the values in 'arr[]'
 * Parameters:
 *   arr    (int[]): values of each row in the histogram
 *   length (int):   length of 'arr[]'; number of rows
 * Return Value:
 *   Doesn't return anything. (Note: characters are printed to stdout)
 * Description:
 *   Starts at 'arr[1]'. Call the current index 'cur'. The number of '#'
 *   characters printed is determined by the value at 'arr[cur]'.
*/
void drawHorizontal(int* arr, int length);
/*
 * Summary:
 *   Prints a vertical histogram using the values in 'arr[]'
 * Parameters:
 *   arr    (int[]): values of each column in the histogram
 *   length (int):   length of 'arr[]'; number of columns
 * Return Value:
 *   Doesn't return anything. (Note: characters are printed to stdout)
 * Description:
 *   Call the largest value in 'arr[]' 'maxHeight'. Two for-loops (one nested in
 *   the other) are used. The outer loop starts at 'maxHeight' and is decremented
 *   by 1 on each iteration. Call this value 'curHeight'. The inner loop
 *   iterates over all the values in 'arr[]' starting at 'arr[1]'. Call this
 *   value 'index'. If 'arr[index]' is greater than or equal to 'curHeight', a
 *   '#' character is printed to stdout. Otherwise a space is printed.
*/
void drawVertical(int* arr, int length);
/*
 * Summary:
 *   Returns the largest value in 'arr[]'
 * Parameters:
 *   arr    (int[]): integer values
 *   length (int):   length of 'arr[]'
 * Return Value:
 *   Largest value in 'arr[]' (int)
 * Description:
 *   Iterates over 'arr[]' comparing each value against the largest value found
 *   so far. That value is returned
*/
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
    putchar('\n');
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
    int curMax = INT_MIN;
    for (int i = 0; i < length; i++) {
        if (arr[i] > curMax) {
            curMax = arr[i];
        }
    }
    return curMax;
}
