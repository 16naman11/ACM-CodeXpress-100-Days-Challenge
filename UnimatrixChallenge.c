/*Its game time! We have an interesting game for you and your friend, imagine that you have a mxn number matrix, you give an integer x to your friend. He or she can add or subtract the number x from any element in the matrix. The task for your friend is to create a uni value matrix which means all the elements of the matrix should be equal or should have equal value by performing the operations of addition and subtraction on elements of the matrix using the number x. You need to output the minimum number of operations performed by your friend to make the matrix uni-value. If it is not possible to make one, output -1.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int m, n, x;
        scanf("%d %d %d", &m, &n, &x);
        long int a[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%ld", &a[i][j]);
            }
        }
        int min = 1000;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = a[i][j];
                int diff;
                int count = 0;
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < n; l++) {
                        if (a[k][l] == temp) {
                            continue;
                        } else {
                            if (temp < a[k][l]) {
                                diff = a[k][l] - temp;
                            } else {
                                diff = temp - a[k][l];
                            }
                        }
                        if (diff % x == 0) {
                            count += diff / x;
                        } else {
                            printf("-1\n");
                            return 0; 
                        }
                    }
                }
                if (count < min) {
                    min = count;
                }
            }
        }
        printf("%d\n", min);
    }

    return 0;
}
