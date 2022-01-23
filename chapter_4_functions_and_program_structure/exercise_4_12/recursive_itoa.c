// Adapt the ideas of printd to write a recursive version of itoa;
// that is, convert an integer into a string by calling a recursive routine.
#include <stdio.h>

#define MAXLINE 32

void int_to_str(int n, char str_to_put[]);

void printd(int n);

int main() {
    char test_str[MAXLINE];
    int test_int = -1243249097;

    printd(test_int);
    putchar('\n');
    int_to_str(test_int, test_str);
    printf("The string converted from int & printed: %s\n", test_str);
}


void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

void int_to_str(int n, char str_to_put[]) {
    static int i;
    if (n < 0) {
        str_to_put[i++] = '-';
        n = -n;
    }
    if (n / 10) {
        int_to_str(n / 10, str_to_put);
    }
    str_to_put[i++] = n % 10 + '0';
    str_to_put[i] = '\0';
}