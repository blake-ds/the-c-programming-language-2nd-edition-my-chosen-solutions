#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 64

double atof(char str[]);

//double pow(double x, double y);


int main() {
    char test_str[MAXLINE] = "123.45e-3";
    double result;

    result = atof(test_str);
    printf("String after conversion to float: %12.6f\n", result);
}

double atof(char str[]) {
    int i, sign, scientific_sign;
    double val, scientific_val, power, scientific;
    scientific_sign = 1;
    // skip whitespace
    for (i = 0; isspace(str[i]); i++);
    // get sign
    sign = (str[i] == '-') ? -1 : 1;
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }
    // get integer part
    for (val = 0.0; isdigit(str[i]); i++) {
        val = val * 10 + (str[i] - '0');
    }
    // find dot
    if (str[i] == '.') {
        i++;
    }
    // get the part past dot
    for (power = 1.0; isdigit(str[i]); i++) {
        val = val * 10 + (str[i] - '0');
        power *= 10.0;
    }
    // handle scientific notation

    if (str[i] == 'e' || str[i] == 'E') {
        i++;

        // handle sign
        if (str[i] == '-') {
            scientific_sign = -1;
            i++;
        }

        scientific = 0;
        for (; isdigit(str[i]); i++) {
            scientific = scientific * 10 + (str[i] - '0');
        }
        scientific = scientific * scientific_sign;
        printf("SCIENTIFIC SIGN: %d\n", scientific_sign);
        printf("SCIENTIFIC EXPONENT: %f\n", scientific);

        scientific = pow(10, scientific);
        printf("SCIENTIFIC IN DECIMAL: %f\n", scientific);
    } else {
        scientific = 1;
    }

    return sign * val / power * scientific;
}
