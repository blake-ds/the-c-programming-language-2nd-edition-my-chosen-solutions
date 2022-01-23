#include <stdio.h>

#define swap(t, x, y) { \
    t _temp;             \
    _temp = x;           \
    x = y;               \
    y= _temp;            \
} // none of the arguments name can be _temp

int main() {
    double arg1, arg2;
    arg1 = 3.532;
    arg2 = 123123.2;

    swap(double, arg1, arg2)
    printf("%f %f\n", arg1, arg2);
}
