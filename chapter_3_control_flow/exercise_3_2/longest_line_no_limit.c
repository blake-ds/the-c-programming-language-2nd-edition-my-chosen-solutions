#include <stdio.h>

#define MAX_STRING_LENGTH 256

void escape(char[], char[]);

int main() {
    char target_test_string[MAX_STRING_LENGTH];
    char source_test_string[] = "This is \nthe best\nthing\t\tin the world.";
    escape(source_test_string, target_test_string);
    printf("SOURCE:\t%s\n", source_test_string);
    printf("TARGET:\t%s\n", target_test_string);
}

void escape(char source[], char target[]) {
    int i, j;
    for (i = j = 0; source[i] != '\0'; i++, j++) {
        switch (source[i]) {
            case '\t':
                target[j++] = '\\';
                target[j] = 't';
                break;
            case '\n':
                target[j++] = '\\';
                target[j] = 'n';
                break;
            default:
                target[j] = source[i];
                break;
        }
    }
}