#define MAX 100
#define MAXWORD 100

#include "getch_ungetch.c"
#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim);

int main(int argc, char *argv[]) {
    int output, lim = MAX;
    char word[MAXWORD];

    while ((output = getword(word, MAXWORD)) != EOF) {
        printf("OUTPUT: %c\n", output);
    }
}

int comment(void) {
    int c;
    while ((c = getch()) != EOF) {
        if (c == '*') {
            if ((c = getch()) == '/') {
                break;
            } else {
                ungetch(c);
            }
        }
    }
    return c;
}

int getword(char *word, int lim) {
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    // skip whitespace
    while (isspace(c = getch()));

    if (c != EOF) {
        *w++ = c;
    }
    if (isalpha(c) || c == '_' || c == '#') {
        for (; --lim > 0; w++) {
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
        }

    } else if (c == '\'' || c == '"') {
        for (; --lim > 0; w++) {
            if ((*w = getch()) == '\\') {
                *++w = getch();
            } else if (*w == c) {
                w++;
                break;
            } else if (*w == EOF) {
                break;
            }
        }
    } else if (c == '/') {
        if ((d = getch()) == '*') {
            c = comment();
        } else {
            ungetch(d);
        }
    }

    *w = '\0';
    return word[0];
}
