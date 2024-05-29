/*Given a string S of alphanumeric characters, you must select a subset of those characters and arrange them to form the longest possible palindromic string. Print the length of longest possible palindromic string.*/

#include <stdio.h>
#include <string.h>

int longestPalindrome(char *s) {
    int count[256] = {0}; 

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
    }

    int odd = 0; 
    int length = 0; 

    for (int i = 0; i < 256; i++) {
        length += (count[i] / 2) * 2; 

        if (count[i] % 2 == 1) {
            odd = 1;
        }
    }

    return length + odd; 
}

int main() {
    int T;
    scanf("%d", &T); 

    while (T--) {
        char S[1001];
        scanf("%s", S); 

        int result = longestPalindrome(S); 

        printf("%d\n", result); 
    }

    return 0;
}