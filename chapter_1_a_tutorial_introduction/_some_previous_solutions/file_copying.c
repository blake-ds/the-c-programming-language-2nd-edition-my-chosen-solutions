#include "stdio.h"

#define N_CHARS 26
#define CAPITAL_TO_SMALL_OFFSET  32
#define ASCII_FIRST_CHAR_NUMBER 65

int main() {
    int c, current_char;
    int characters[N_CHARS], char_counts[N_CHARS];
    printf("characters: ");
    for (int i = 0; i < N_CHARS; ++i) {
        char_counts[i] = 0;
        current_char = characters[i] = ASCII_FIRST_CHAR_NUMBER + i;
        printf("%c ", current_char);
    }
    printf("\nENTER INPUT:\n");


    while ((c = getchar()) != EOF) {
        for (int i = 0; i < N_CHARS; ++i) {
            if (c == characters[i] || c == characters[i] + CAPITAL_TO_SMALL_OFFSET) {
                // printf("CHAR FOUND: %c\n", c);
                ++char_counts[i];
            } else {
                // printf("CHAR NOT FOUND: %c\n", characters[i]);
            }
        }
    }
    for (int i = 0; i < N_CHARS; ++i) {
        printf("CHAR: %c\t", characters[i]);
        for (int j = 0; j < char_counts[i]; ++j) {
            putchar(254);
        }
        printf("\n");
    }
}
