#include <stdio.h>

int one_bit_count(unsigned);

int main() {
    printf("%d\n", one_bit_count(25));
}


int one_bit_count(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }
    return b;
};
