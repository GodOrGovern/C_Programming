/*
 * Modify the temperature conversion program to print a heading
 * above the table
*/

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower = 0, upper = 300, step = 20;

    printf("Fahrenheit | Celsius\n");
    printf("---------------------\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f | %6.1f\n", fahr, celsius);
        fahr += step;
    }

    return 0;
}
