#include <stdio.h>

#define BUFFER_SIZE 100
char buffer[BUFFER_SIZE];
int buffer_position;

int getch(void) {
    return (buffer_position > 0) ? buffer[--buffer_position] : getchar();
}

void ungetch(int c) {
    if (buffer_position >= BUFFER_SIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buffer[buffer_position++] = c;
    }
}
