/*You are given an array of n cosmic objects, each with a numerical value representing its mass. Find the stable object in the array. A stable object is one whose mass is equal to the number of times it appears in the array.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1)
        return n;

    int temp[n];

    int j = 0;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];

    temp[j++] = arr[n - 1];

    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int stable;
        int flag = 0, x = 0, b[n];
        for (int i = 0; i < n; i++) {
            stable = 0;
            for (int j = 0; j < n; j++) {
                if (a[i] == a[j]) {
                    stable++;
                }
            }
            if (stable == a[i]) {
                b[x] = stable;
                x++;
                flag = 1;
            }
        }
        if (flag) {
            qsort(b, x, sizeof(int), compare);
            int newSize = removeDuplicates(b, x);
            for (int i = 0; i < newSize; i++) {
                printf("%d ", b[i]);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
