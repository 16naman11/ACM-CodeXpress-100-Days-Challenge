/*You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Print Yes and the side of square if you can make this square and No otherwise.*/


#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long int a[n], sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%ld", &a[i]);
            sum += a[i];
        }

        if (sum % 4 != 0) {
            printf("No\n");
            continue;
        }

        qsort(a, n, sizeof(long int), compare);

        long int target_side = sum / 4;
        long int sides[4] = {0};
        int flag = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                if (sides[j] + a[i] <= target_side) {
                    sides[j] += a[i];
                    break;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] != target_side) {
                flag = 1;
                break;
            }
        }

        if (flag) {
            printf("No\n");
        } else {
            printf("Yes %ld\n", target_side);
        }
    }
    return 0;
}
