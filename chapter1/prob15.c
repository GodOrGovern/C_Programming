/* Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion */

#include <stdio.h>

float fahrToCelsius(float fahr);

int main(void)
{
    float fahr;

    int lower = 0;
    int upper = 300;
    int step = 20;

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %0.1f\n", fahr, fahrToCelsius(fahr));
        fahr += step;
    }

    return 0;
}

float fahrToCelsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}
