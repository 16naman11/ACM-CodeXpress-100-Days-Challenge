/*
Imagine you have a magical scroll with a word s written on it. You want to cut the scroll into smaller pieces, but you have to follow these rules:

Each piece must have at least one letter on it.
No letter can appear on more than one piece.
When you put the pieces together, they must form the original word s.
Cut the word in maximum number of pieces possible.
How long is each piece? Print your answer as a list of numbers, where each number is the length of a piece.

*/

#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char s[1001];
        scanf("%s", s);

        int length = strlen(s);
        int last_index[26];

     
        for (int i = 0; i < 26; i++) {
            last_index[i] = -1;
        }

   
        for (int i = 0; i < length; i++) {
            last_index[s[i] - 'a'] = i;
        }

   
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = (end > last_index[s[i] - 'a']) ? end : last_index[s[i] - 'a'];

            if (i == end) {

                printf("%d ", end - start + 1);
                start = end + 1;
            }
        }

        printf("\n");
    }

    return 0;
}