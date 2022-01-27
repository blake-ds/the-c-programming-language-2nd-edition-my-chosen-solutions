#include <stdio.h>

char *str_concat(char *base, char *to_concat);

int main() {
    char test_string_1[1000] = "Base string. "; /* Assigning a lot to avoid Core Dump */
    char test_string_2[] = "This will be concatenated to the base string.\n";
    char test_string_3[] = "This will be ANOTHER concat.\n";

    printf(
            "%s",
            str_concat(str_concat(test_string_1, test_string_2), test_string_3)
    );
}

char *str_concat(char *base, char *to_concat) {
    char *str_beginning = base; /*Save the position of the string beginning*/
    while (*base) base++; /* Find the end */
    while (*base++ = *to_concat++);  /* Concat */
    return str_beginning;
}