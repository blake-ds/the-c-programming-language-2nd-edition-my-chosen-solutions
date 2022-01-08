//    Revise the main routine of the longest-line program, so it will
//    correctly print the length of arbitrarily long input lines,
//    and as much as possible of the text.

#include <stdio.h>

#define MAXLINE 32 /* maximum input line size */

int SaveInputToLine(char line_to_read_into[], int limit_line_length);

void CopyLineFromTo(char to[], char from[]);

void Reverse(char line_to_reverse[], char return_to[]);

// print longest input line
int main() {
    char current_line[MAXLINE], current_line_reversed[MAXLINE];

    while (SaveInputToLine(current_line, MAXLINE) > 0) /* while there's input */ {

        Reverse(current_line, current_line_reversed);
        printf("Current line:\t%s\nReversed:\t%s\n", current_line, current_line_reversed);
        // take 1 line of input and save it to sting
        // reverse the string
        // print the reversed string
    }
    return 0;
}

int SaveInputToLine(char line_to_read_into[], int limit_line_length) {
    // if return is 0, there was no line
    int c, i;

    for (i = 0; i < limit_line_length - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line_to_read_into[i] = c;
    }
    if (c == '\n') {
        line_to_read_into[i] = c;
        ++i;
    }
    line_to_read_into[i] = '\0';
    return i;
}

void Reverse(char line_to_reverse[], char return_to[]) {
    int str_len, i, j;

    for (str_len = 0; line_to_reverse[str_len] != '\0'; ++str_len);

    j = 0;
    for (i = str_len - 1; i >= 0; --i) {
        if (line_to_reverse[i] == '\n') continue;
        return_to[j] = line_to_reverse[i];
        ++j;
    }
    return_to[j] = '\n';
    ++j;
    return_to[j] = '\0';


}
