/*Given a string s, partition s such that every substring of the partition is a palindrome . Print the number of all possible palindrome partitioning of s.*/
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
   




int isPalindrome(char str[], int start, int end) {

    while (start < end) {

        if (str[start++] != str[end--]) {

            return 0; 

        }

    }

    return 1; 

}

void countPalindromePartitions(char str[], int start, int len, int *count) {

    if (start >= len) {

        (*count)++;

        return;

    }

    for (int i = start; i < len; i++) {

        if (isPalindrome(str, start, i)) {

            countPalindromePartitions(str, i + 1, len, count);

        }

    }

}

int main() {

    int T;

    scanf("%d", &T);

    while (T--) {

        char s[17]; 

        scanf("%s", s);

        int count = 0;

        int length = strlen(s);

        countPalindromePartitions(s, 0, length, &count);

        printf("%d\n", count);

    }

    return 0;

}