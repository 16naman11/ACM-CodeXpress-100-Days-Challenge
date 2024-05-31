/*Inosuke and Zenitsu are playing a game. They are given two strings a and b. Inosuke would win if a is a subsequence of b and if its not then Zenitsu would win. Write a program that outputs the winner of game.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).*/

#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        char a[10000], b[10000];
        scanf("%s", a);
        scanf("%s", b);

        int len1 = strlen(a);
        int len2 = strlen(b);

        int j = 0;
        for (int k = 0; k < len2 && j < len1; k++) {
            if (b[k] == a[j]) {
                j++;
            }
        }

        if (j == len1) {
            printf("Inosuke\n");
        } else {
            printf("Zenitsu\n");
        }
    }

    return 0;
}
