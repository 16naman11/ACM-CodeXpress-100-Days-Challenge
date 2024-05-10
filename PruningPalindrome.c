/*Dev has a palindromic string of lowercase English letters palindrome, he needs to perform a pruning operation on string that is to replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

Help Dev write a code that outputs the resulting string after performing pruning operation. If there is no way to replace a character to make it not a palindrome, output -1.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[1000];
        scanf("%s",s);
        int n = strlen(s);
        if (n == 1) {
            printf("-1\n");
            continue;
        }
        int flag=0;
        for (int i = 0; i <n/2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                flag=1;
                printf("%s\n", s);
                break;
            }
        }
        if(!flag && s[n-1]=='a'){
            s[n - 1] = 'b';
            printf("%s\n", s);
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}