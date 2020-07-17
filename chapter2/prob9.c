/*
 * In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of
 * bitcount.
*/

/*
 * When 1 is subtracted from x, the rightmost 1-bit becomes a 0, all bits to
 * the right of it become 1, and all bits to the left remain the same. When
 * this value is &'ed with x, the rightmost 1-bit is paired with a 0 making the
 * resulting bit a 0. All other bits remain the same.
*/

/*
 * Summary:
 *   Count number of 1 bits in 'x'
 * Parameter:
 *   x (uint): value for which 1 bits are counted
 * Return Value:
 *   Number of 1 bits in 'x'
 * Description:
 *   Uses the fact that 'x &= (x - 1)' deletes the rightmost 1-bit of 'x' to
 *   count the number of 1 bits in 'x'
*/
int bitcount(unsigned int x)
{
    int b;
    while (x) {
        x &= x - 1;
        b += 1;
    }
    return b;
}
