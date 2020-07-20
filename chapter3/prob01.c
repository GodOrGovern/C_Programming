/*
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside.) Write a version with only one test
 * inside the loop and measure the difference in run-time.
*/

/*
 * The modified binsearch() is slightly faster, finding the answer in about 90%
 * of the time the original takes
*/

/* Summary:
 *   Determine if 'x' is in array 'v[]'. If so, return the index, otherwise
 *   return -1
 * Parameters:
 *   x (int):   value being searched for
 *   v (int[]): array being searched
 *   n (int):   number of elements in 'v[]'
 * Return Value:
 *   The index where 'x' is found or -1 if it is not found
 * Description:
 *   Simple binary search
*/
int binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    while (low < high && v[mid] != x) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return (v[mid] == x) ? mid : -1;
}
