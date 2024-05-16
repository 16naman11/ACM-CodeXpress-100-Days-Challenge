/*Its the World Cup season and the Indian Squad is just smashing its opponent one after the other in a row making us invincible!! How can one forget the sensational half century of the centuries scored by the King of Cricket , the G.O.A.T - Virat Kohli. You are given an array of runs scored by the King in any number of overs throughout the match. Your task is to sort the runs in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order. Output the array of runs after sorting it.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int size;
        scanf("%d", &size);
        int a[size];
        for (int j = 0; j < size; j++) {
            scanf("%d", &a[j]);
        }

        int b[size];
        for (int k = 0; k < size; k++) {
            b[k] = 0;
            int num = a[k];
            while (num > 0) {
                b[k] += (num & 1);
                num >>= 1;
            }
        }

        for (int j = 0; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (b[j] > b[k] || (b[j] == b[k] && a[j] > a[k])) {
                    int temp = b[j];
                    b[j] = b[k];
                    b[k] = temp;

                    temp = a[j];
                    a[j] = a[k];
                    a[k] = temp;
                }
            }
        }

        for (int j = 0; j < size; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }

    return 0;
}
