//    Revise the main routine of the longest-line program, so it will
//    correctly print the length of arbitrarily long input lines,
//    and as much as possible of the text.

#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */
#define PRINTING_THRESHOLD 80

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
            if (current_line_length >=  PRINTING_THRESHOLD) {
                printf("%s", current_input_line);
            }
        }
    }

    if (max_line_length_seen > 0) /* There was a line */ {
        printf("Longest line is (truncated if longer than %d): %s\n", MAXLINE, current_longest_line);
        printf("It's length is: %5d\n", max_line_length_seen);
    }
    return 0;
}

int GetLineLengthAndSaveLine(char line_to_read_into[], int limit_line_length) {
    int c, len_counter, string_position;

    string_position = 0;
    for (len_counter = 0; (c = getchar()) != EOF && c != '\n'; ++len_counter) {
        if (len_counter < limit_line_length - 2) /* line not exceeding limit */{
            line_to_read_into[string_position] = c;
            ++string_position;
        }
        // len counter continues increasing after string line limit has been achieved
    }
    if (c == '\n') {
        line_to_read_into[string_position] = c;
        ++len_counter;
        ++string_position;
    }
    line_to_read_into[string_position] = '\0';
    return len_counter;
}

void CopyLineFromTo(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}