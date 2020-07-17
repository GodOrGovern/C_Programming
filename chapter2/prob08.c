/*
 * Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n positions.
*/

/*
 * Summary:
 *   Return the value of 'x' rotated to the right by 'n' positions
 * Parameters:
 *   x (uint): value being rotated
 *   n (int):  number of positions to rotate 'x'
 * Return Value:
 *   'x' rotated to the right by 'n' positions
 * Descriptions:
 *   Returns 'x' shifted to the right by 'n' positions added to the first 'n'
 *   bits (from the right) shifted all the way to the left
*/
unsigned int rightrot(unsigned int x, int n)
{
    int bits = sizeof(x) * 8;
    n %= bits;
    return (x >> n) + ((x & ((1 << n) - 1)) << (bits - n));
}
