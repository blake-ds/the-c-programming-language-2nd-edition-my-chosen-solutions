//    Revise the main routine of the longest-line program, so it will
//    correctly print the length of arbitrarily long input lines,
//    and as much as possible of the text.

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

int GetLineLengthAndSaveLine(char line_to_read_into[], int limit_line_length);

void CopyLineFromTo(char to[], char from[]);

// print longest input line
int main() {
    int current_line_length, max_line_length_seen;
    char current_input_line[MAXLINE], current_longest_line[MAXLINE];

    max_line_length_seen = 0;

    // while there's next line
    while ((current_line_length = GetLineLengthAndSaveLine(current_input_line, MAXLINE)) > 0) {
        if (current_line_length > max_line_length_seen) {
            max_line_length_seen = current_line_length;
            CopyLineFromTo(current_longest_line, current_input_line);
        }
    }

    if (max_line_length_seen > 0) /* There was a line */ {
        printf("Longest line is: %s\n", current_longest_line);
        printf("It's length is: %5d\n", max_line_length_seen);
    }
    return 0;
}

int GetLineLengthAndSaveLine(char line_to_read_into[], int limit_line_length) {
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

void CopyLineFromTo(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}