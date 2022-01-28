#include <stdio.h>

void set_month_day_from_day_of_year(int, int, int *, int *);

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int main() {
    int test_year = 1981, test_day = 366;
    int result_month, result_day;
    printf("TESTING set_month_day_from_day_of_year\n");
    printf("initial values: test_year=%d; test_day=%d\n", test_year, test_day);
    set_month_day_from_day_of_year(test_year, test_day, &result_month, &result_day);
    printf("result values:  result_year=%d; result_day=%d\n", result_month, result_day);
}

void set_month_day_from_day_of_year(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    if (year < 1) {
        *pday = -1;
        *pmonth = -1;
        return;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    int max_n_days = leap ? 366 : 355;
    if (yearday > max_n_days) {
        *pday = -1;
        *pmonth = -1;
        return;
    }
    for (i = 0; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    *pday = yearday;
    *pmonth = i;
}