/*Can you guess today is which day of the year? Let’s check your capability of finding out the correct day of the year when you are given the DATE!. You are given a Date as an input and your task is to determine the day of the year which falls on the given Date. So, get ready to go on a date with the DATE! (Assume that the year is non leap year).*/

#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int date, days = 0;
        char month[4];
        scanf("%d %s", &date, month);

        if (strcmp(month, "JAN") == 0) {
            days = date;
        } else if (strcmp(month, "FEB") == 0) {
            days = 31 + date;
        } else if (strcmp(month, "MAR") == 0) {
            days = 59 + date;
        } else if (strcmp(month, "APR") == 0) {
            days = 90 + date;
        } else if (strcmp(month, "MAY") == 0) {
            days = 120 + date;
        } else if (strcmp(month, "JUN") == 0) {
            days = 151 + date;
        } else if (strcmp(month, "JUL") == 0) {
            days = 181 + date;
        } else if (strcmp(month, "AUG") == 0) {
            days = 212 + date;
        } else if (strcmp(month, "SEP") == 0) {
            days = 243 + date;
        } else if (strcmp(month, "OCT") == 0) {
            days = 273 + date;
        } else if (strcmp(month, "NOV") == 0) {
            days = 304 + date;
        } else if (strcmp(month, "DEC") == 0) {
            days = 334 + date;
        }

        printf("%d\n", days);
    }

    return 0;
}
