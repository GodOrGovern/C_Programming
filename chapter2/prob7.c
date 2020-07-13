/*
 * Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
 * others unchanged.
*/

#include <stdio.h>

/*
 * Summary:
 *   Return 'x' with the 'n' bits starting at position 'p' inverted
 * Parameters:
 *   x (int): all bits except for the 'n' bits beginning at position 'p'
 *   p (int): position where bits in 'x' will be inverted
 *   n (int): number of bits in 'x' to invert
 * Return Value:
 *   'x' with the 'n' bits at position 'p' inverted
 * Description:
 *   'x' is XORed with a bit string that is 0 everywhere except for the 'n'
 *   bits at position 'p'. The result is returned
*/
int invert(int x, int p, int n)
{
    return x ^ (((1 << n) - 1) << (p-n+1));
}
