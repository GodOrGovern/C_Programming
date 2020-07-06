/*
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column
*/

#include <stdio.h>
#include <ctype.h>

// Max length of input line
#define MAXLINE 1000
// Max length of each folded line
#define FOLD 5

/*
 * Summary:
 *   Folds a line
 * Parameters:
 *   line:   characters being folded
 *   remain: number of characters that still have to be folded
 *   start:  position in 'line' where the folding starts
 *   length: maximum length of each folded line
 * Return Value:
 *   Nothing is returned. (Note: characters are printed to stdout)
 * Description:
 *   If 'remain' is greater than 'length', 'line' is folded at the last non-blank
 *   character before 'line[start+remain]'. If there is no non-blank character,
 *   it is folded at 'line[start+remain]'. Call the spot where it is folded
 *   'end'. The characters from 'line[start]' to 'line[end]' are printed. The
 *   function then calls itself with updated values:
 *     foldLine(line, remain-(end-start), end, length)
 *   If 'remain' is not greater than 'length' the characters from 'line[start]'
 *   to 'line[start+remain]' are printed and the program terminates.
 * Bugs:
 *   If there are two adjacent whitespace characters, the first being at the
 *   position where 'line' is folded, they are printed on the same line.
 */
void foldLine(char line[], int remain, int start, int length);
/*
 * Summary:
 *   Copy a line from stdin to the array 'line'
 * Parameters:
 *   line:  stores the copied characters
 *   limit: maximum number of characters to be copied
 * Return Value:
 *   The number of characters in the copied line is returned. (Note: 'line' is
 *   modified in place)
 * Description:
 *   Up to 'limit' characters are copied from stdin to the array 'line', which
 *   is modified in place. The length of the copied line is returned.
*/
int getLine(char line[], int limit);

int main(void)
{
    int len = 0;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        foldLine(line, len, 0, FOLD);
    }

    return 0;
}

void foldLine(char line[], int remain, int start, int length)
{
    if (remain > length) {
        int blank = start + length;
        for (; blank > start && !(isspace(line[blank])); blank--);
        int end = blank == start ? start+length : blank+1;
        for (int i = start; i < end; putchar(line[i]), i++);
        putchar('\n');
        foldLine(line, remain-(end-start), end, length);
    } else {
        for (int i = start; i < start+remain; i++) {
            putchar(line[i]);
        }
    }
}

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
