/*
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
*/

#include <stdio.h>

/*
 * Summary:
 *   Replace the 'n' bits that begin at position 'p' in 'x' with the right-most
 *   'n' bits of 'y'
 * Parameters:
 *   x (uint): all bits except for the 'n' bits beginning at position 'p'
 *   p (int): position where bits in 'x' will be substituted for bits in 'y'
 *   n (int): number of bits in 'x' to replace with bits from 'y'
 *   y (uint): 'n' right-most bits are substituted into 'x'
 * Return Value:
 *   'x' with the 'n' bits at position 'p' substituted with the right-most 'n'
 *   bits of 'y'
 * Description:
 *   First all the bits to the left of position 'p' in 'x' are found. This is
 *   added to the right-most 'n' bits of 'y' (shifted to the appropriate
 *   position). Finally, the trailing bits that remain from 'x' are added. The
 *   final sum is returned
*/
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    return (x & ~((1 << (p+1)) - 1)) + ((y & (1 << n) - 1) << (p-n+1)) + (x & (1 << (p-n)) - 1);
}
