#include <stdio.h>

int lower(int);

int main() {
    printf("%c\n", lower('F'));
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
};
