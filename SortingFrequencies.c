/*You are given a string s of alphanumeric characters, write a code that outputs the string by modifying it such that all the characters are sorted in descending order of their frequencies. If there exist two characters with the same frequency output them in ascending order of their ASCII values.*/

#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        char name[10001];
        scanf("%s", name);

        int freq[256] = {0}; 

        
        for (int i = 0; i < strlen(name); i++) {
            freq[(unsigned char)name[i]]++; 
        }

        
        int maxFreq = 0;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }

        for (int f = maxFreq; f > 0; f--) {
            for (int i = 0; i < 256; i++) {
                if (freq[i] == f) {
                    for (int j = 0; j < freq[i]; j++) {
                        printf("%c", (char)i); 
                    }
                }
            }
        }

        printf("\n");
    }

    return 0;
}