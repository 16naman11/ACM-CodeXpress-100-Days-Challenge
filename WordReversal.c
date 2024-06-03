/*Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position. All the English letters (lowercase or uppercase) should be reversed.

Print s after reversing it.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char s[1000];
        scanf("%s", s);
        int len = strlen(s);
        int i = 0, j = len - 1;
        char temp;
        while (i < j) {
            if ((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')) {
                i++;
            } else if ((s[j] < 'a' || s[j] > 'z') && (s[j] < 'A' || s[j] > 'Z')) {
                j--;
            } else if ((s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') &&
                       (s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z')) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        printf("%s\n", s);
    }
    return 0;
}
