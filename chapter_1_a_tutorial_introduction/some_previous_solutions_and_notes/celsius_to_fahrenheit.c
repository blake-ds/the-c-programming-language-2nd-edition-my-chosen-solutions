#include <stdio.h>

#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* lower limit of table */
#define STEP  20 /* lower limit of table */

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("F TO C CONVERSION TABLE\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5.0 / 9.0 * (fahr - 32.0);
        printf("\t%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    printf("C TO F CONVERSION TABLE\n");
    for (celsius = LOWER; celsius >= UPPER; celsius = celsius - STEP) {
        printf("\t%3.0f\t%6.1f\n", celsius, 9 * celsius / 5.0 + 32);
    }
}
