/*You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

Print the largest possible value of num after any number of swaps.*/


#include <stdio.h>

int sameParity(int a, int b) {
    return (a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0);
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void largestPossibleNum(char num[]) {
    int len = 0;
    while (num[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (sameParity(num[i] - '0', num[j] - '0') && num[i] < num[j]) {
                swap(&num[i], &num[j]);
            }
        }
    }

    printf("%s\n", num);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char num[15]; 
        scanf("%s", num);
        largestPossibleNum(num);
    }

    return 0;
}