/*
 * Modify the temperature conversion program to print the table in
 * reverse order, that is, from 300 degrees to O
*/

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower = 0, upper = 300, step = 20;

    puts("Fahrenheit | Celsius");
    puts("---------------------");

    fahr = upper;
    while (fahr >= lower) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f | %6.1f\n", fahr, celsius);
        fahr -= step;
    }

    return 0;
}
