#include <stdio.h>
#include <limits.h>

// Determine ranges of tpyes
int main() {
    printf("SIGNED\n");
    printf("char min max:\t%d\t%d\n", SCHAR_MIN, SCHAR_MAX);
    printf("short min max:\t%d\t%d\n", SHRT_MIN, SHRT_MAX);
    printf("int min max:\t%d\t%d\n", INT_MIN, INT_MAX);
    printf("long min max:\t%ld\t%ld\n", LONG_MIN, LONG_MAX);

    printf("UNSIGNED\n");
    printf("char max:\t%d\n", UCHAR_MAX);
    printf("short max:\t%d\n", USHRT_MAX);
    printf("int max:\t%d\n", UINT_MAX);
    printf("long max:\t%ld\n", ULONG_MAX);

    // Using bitwise operations
    printf("char min:\t%d\n", ~(char) ((unsigned char) ~0 >> 1));
}
