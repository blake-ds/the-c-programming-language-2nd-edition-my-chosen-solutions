#include <stdio.h>

void squeeze(char[], int);

void replace_char_in_string(char[], int, char);

void delete_each_char_in_string_which_exists_in_another_string(char[], char[]);


int check_if_char_in_string(char[], char);

int main() {
    char test_string_1[] = "This is a test string";
    char test_string_2[] = "This is a test string";
    char test_string_3[] = "This is a test string";
    squeeze(test_string_1, 's');
    printf("%s\n", test_string_1);

    replace_char_in_string(test_string_2, 's', 'S');
    printf("%s\n", test_string_2);


    char string_of_chars_to_remove[] = "st";
    delete_each_char_in_string_which_exists_in_another_string(test_string_3, string_of_chars_to_remove);
    printf("%s\n", test_string_3);

};

void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void replace_char_in_string(char s[], int char_to_replace, char char_to_replace_with) {
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == char_to_replace) {
            s[i] = char_to_replace_with;
        }
    }
}

void delete_each_char_in_string_which_exists_in_another_string(char s1[], char s2[]) {
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++) {
        if (check_if_char_in_string(s2, s1[i]) == 0) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}


int check_if_char_in_string(char s[], char c) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return 1;
        }
    }
    return 0;
}