/* Write a program to print the corresponding Celsius to Fahrenheit
 * table */

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius | Fahrenheit\n");
    printf("---------------------\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = 1.8 * celsius + 32;
        printf("%7.0f | %6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}
