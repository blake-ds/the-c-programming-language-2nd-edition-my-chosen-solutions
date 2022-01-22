#include <stdio.h>

#define MAXLINE 1000

int get_line(char str_to_read_into[], int limit);

int get_rightmost_substring_start_index(char source[], char substring[]);

char pattern[] = "ould"; /* what we look for */

int main() {
    char line[MAXLINE];
    int found = 0;
    int substring_start_i;

    while (get_line(line, MAXLINE) > 0) {
        if ((substring_start_i = get_rightmost_substring_start_index(line, pattern)) >= 0) {
            printf("%s\n", line);
            printf("RIGHTMOST SUBSTRING START INDEX: %6d\n", substring_start_i);
            found++;
        }
    }
    return found;
}

int get_line(char str_to_read_into[], int limit) {
    int c, i;

    i = 0;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n') {
        str_to_read_into[i++] = c;
    }
    if (c == '\n') {
        str_to_read_into[i++] = c;
    }
    str_to_read_into[i] = '\0';
    return i;
}

int get_rightmost_substring_start_index(char source[], char substring[]) {
    int i, j, k, rightmost_index;
    rightmost_index =-1;
    for (i = 0; source[i] != '\0'; i++) {
        for (j = i, k = 0; substring[k] != '\0' && source[j] == substring[k]; j++, k++) { ;
        }
        if (k > 0 && substring[k] == '\0') {
            rightmost_index = i;
        }
    }
    return rightmost_index;
}
