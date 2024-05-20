/*Suppose you have a array of numbers dist, of n elements that represent the distances of some galaxies from Earth in light-years. Find the third farthest galaxy in this list. If there are less than three distinct distances, output the farthest one.*/


#include <stdio.h>
#include <stdlib.h>

// Comparator function for sorting in descending order
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int dist[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &dist[i]);
        }

        qsort(dist, n, sizeof(int), compare);

        int thirdFarthest = dist[0];

        int uniqueDistances = 1;
        for (int i = 1; i < n; ++i) {
            if (dist[i] != dist[i - 1]) {
                uniqueDistances++;
            }
            if (uniqueDistances == 3) {
                thirdFarthest = dist[i];
                break;
            }
        }

        printf("%d\n", thirdFarthest);
    }

    return 0;
}