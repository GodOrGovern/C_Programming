/*
 * Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion
*/

#include <stdio.h>

/*
 * Convert the value in 'fahr' from Fahrenheit to Celsius
*/
float fahrToCelsius(float fahr);

int main(void)
{
    int lower = 0, upper = 300, step = 20;
    float fahr = lower;

    puts("Fahrenheit | Celsius");
    puts("---------------------");

    while (fahr <= upper) {
        printf("%10.0f | %6.1f\n", fahr, fahrToCelsius(fahr));
        fahr += step;
    }

    return 0;
}

float fahrToCelsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}
