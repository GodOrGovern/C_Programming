#ifndef HELPERS_H_
#define HELPERS_H_
// Functions that are duplicated amongst programs for Chapter 1 exercises

/* Copy a line from 'stdin' to 'line' up to 'limit' characters. Return the
 * length of 'line' up to 'limit' */
int getLine(char line[], int limit);

/* For each element in 'arr' draw a column with a height equal to the value of
 * that element. 'arr' has 'length' elements */
void drawVertical(int* arr, int length);

/* For each element in 'arr' draw a row with a length equal to the value of
 * that element. 'arr' has 'length' elements */
void drawHorizontal(int* arr, int length);

// Return the maximum value of the array 'arr' with 'length' elements
int maxArr(int* arr, int length);

#endif
