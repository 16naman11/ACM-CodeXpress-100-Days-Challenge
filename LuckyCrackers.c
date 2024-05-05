/*Ram is celebrating Diwali with his family and friends. He has a box of firecrackers that contains different types of firecrackers, such as rockets, chakris, anaars, and phuljharis. Each firecracker has a number written on it, which represents its loudness level. The loudness level of each firecracker is given in the form of an array L of N positive integers.

He also has an array of auspicious numbers A of M numbers that are considered lucky for Diwali. The luckiness score of an auspicious number is the number of firecrackers in the box that have a loudness level divisible by that auspicious number.

Your task is to print the auspicious number with the maximum luckiness score. If there is more than one auspicious number with the maximum score, print the minimum of them.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int T, N, M, i, j, k = 0;
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        int large = 0;
        long int min = 0;
        
        scanf("%d %d", &N, &M);
        
        long int L[N], A[M];
        long int count[M];
        int luckiness[M];
        
        for (j = 0; j < N; j++) {
            scanf("%ld", &L[j]);
        }
        
        for (j = 0; j < M; j++) {
            scanf("%ld", &A[j]);
            count[j] = 0;
            for (k = 0; k < N; k++) {
                if (L[k] % A[j] == 0) {
                    count[j]++;
                }
            }
        }
        
        large = count[0];
        for (j = 1; j < M; j++) {
            if (count[j] > large) {
                large = count[j];
            }
        }
        
        k = 0;
        for (j = 0; j < M; j++) {
            if (large == count[j]) {
                luckiness[k++] = A[j];
            }
        }
        
        min = luckiness[0];
        for (j = 1; j < k; j++) {
            if (luckiness[j] < min) {
                min = luckiness[j];
            }
        }
        
        printf("%ld\n", min);
    }
    
    return 0;
}
