#define MAX 100
#define MAXWORD 100

#include "getch_ungetch.c"
#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim);

int main(int argc, char *argv[]) {
    int output, lim = MAX;
    char word[MAXWORD];

    output = getword(word, lim);
    printf("OUTPUT: %c\n", output);
}

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    // skip whitespace
    while (isspace(c = getch()));

    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    printf("GHERER\n");
    return word[0];
}
