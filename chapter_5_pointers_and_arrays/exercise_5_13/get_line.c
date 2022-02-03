#include <stdio.h>

int get_line(char *line, int max, int verbose) {
    int c, i;

    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
        if (i == 0 && verbose) {
            printf("|");
        }
        *line++ = c;
        i++;

        if (verbose)printf("| CHAR: %d |", c);
    }
    if (c == '\n') {
        *line++ = c;
        i++;
        if (verbose)printf("| CHAR: %d |", c);

    }
    *line = '\0';
    if (verbose) {
        printf("|\n");
        printf("|| CHARCOUNT: %d ||\n", i);
    }
    return i;
};
