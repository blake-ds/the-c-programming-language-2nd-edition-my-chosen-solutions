#include "get_line.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
#define MAXLINES 1000


int get_line(char *line, int max, int verbose);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    char *all_lines[MAXLINES];
    int lineno = 0;
    int c, number = 10, verbose = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
                case 'n':
                    *++argv;
                    number = atoi(*argv);
                    *--argv;
                    break;
                case 'v':
                    verbose = 1;
                    break;
                default:
                    printf("tail: illegal option %c\n", c);
                    argc = 0;
                    number = -1;
                    break;
            }
        }
    }
    if (argc > 1) {
        printf("Usage: tail -n\n");
    } else {
        printf("NUMBER %d | VERBOSE %d\n", number, verbose);
        while ((c = get_line(line, MAXLINE, verbose)) > 0) {
            all_lines[lineno] = strfdup(line);
            lineno++;
        }
    }

    int last_sentences_starting_index = (number > lineno) ? 0 : (lineno - number);
    for (; last_sentences_starting_index < lineno; last_sentences_starting_index++) {
        printf("%d: %s\n", last_sentences_starting_index, all_lines[last_sentences_starting_index]);
    }
    return number;
}
