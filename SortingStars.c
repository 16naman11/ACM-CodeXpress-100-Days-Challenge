/*you have an m x n matrix mat of integers, where each integer represents the brightness of a star in a patch of the sky. A matrix diagonal is a line of stars that forms a diagonal pattern from some star in either the topmost row or leftmost column and going in the bottom-right direction until reaching the edge of the sky. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes stars mat[2][0], mat[3][1], and mat[4][2].

Given the matrix mat of stars, sort each matrix diagonal in ascending order of brightness and print the resulting matrix of the sky.*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int m, n;
        scanf("%d %d", &m, &n);
        int a[m][n];

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &a[j][k]);
            }
        }
        for (int j = 0; j < n; j++) {
            int x = 0;
            int sort[m];
            for (int k = 0, l = j; k < m && l < n; k++, l++) {
                sort[x] = a[k][l];
                x++;
            }
            qsort(sort, x, sizeof(int), compare);
            x = 0;
            for (int k = 0, l = j; k < m && l < n; k++, l++) {
                a[k][l] = sort[x];
                x++;
            }
        }
        for (int j = 1; j < m; j++) {
            int x = 0;
            int sort[n];
            for (int k = j, l = 0; k < m && l < n; k++, l++) {
                sort[x] = a[k][l];
                x++;
            }
            qsort(sort, x, sizeof(int), compare);
            x = 0;
            for (int k = j, l = 0; k < m && l < n; k++, l++) {
                a[k][l] = sort[x];
                x++;
            }
        }
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                printf("%d ", a[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
