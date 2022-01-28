#include <stdio.h>

int strend(char *s, char *t);

int main() {
    char base_string[] = "Let's check if it's there!\n";
    char end_string[] = {'\0'};

    int substring_is_at_the_end = strend(base_string, end_string);
    if (substring_is_at_the_end) {
        printf("Yup, it is!\n");
    } else {
        printf("Nope, not there!\n");
    }

    char another_base_string[] = "Let's check if it's there!\n";
    char another_end_string[] = "there!\n";

    substring_is_at_the_end = strend(another_base_string, another_end_string);
    if (substring_is_at_the_end) {
        printf("Yup, it is!\n");
    } else {
        printf("Nope, not there!\n");
    }

}

int strend(char *s, char *t) {
    // find ends of strings
    int len_t, i;
    for (; *s; *s++);
    for (len_t = 1; *t; *t++, len_t++);
    if (len_t <= 1) {
        // contains null only or not even null
        printf("WARNING: the substring is empty.\n");
        return 0;
    }

    for (i = 0; i < len_t; *s--, *t--, i++) {
        if (*s != *t) {
            return 0;
        }
    }

    return 1;
}