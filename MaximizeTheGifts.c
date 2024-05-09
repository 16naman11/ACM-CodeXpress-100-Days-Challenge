/*The festival of lights is approaching and it’s time to send gifts to family and friends. Shivaay is at a store to buy Diwali presents and he has selected a total of n gifts out of all the gifts available at the store. The price of each present is represented in the form of array L of M elements(where L[i] represent the cost of i th gift in Rupees). He initially has X Rupees to spend and he wants to buy as many gifts as possible. Your task is to find the maximum number of gifts, Shivaay can buy with an available purse of X Rupees.*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, X;
        scanf("%d %d", &M, &X);
        int L[10000]; // Assuming a maximum of 10,000 gifts

        for (int i = 0; i < M; i++) {
            scanf("%d", &L[i]);
        }

        qsort(L, M, sizeof(int), compare);

        int count = 0;

        for (int i = 0; i < M; i++) {
            if (X >= L[i]) {
                X -= L[i];
                count++;
            } else {
                break;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
