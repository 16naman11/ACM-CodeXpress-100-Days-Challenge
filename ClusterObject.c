/*Mikasa and Eren are observing a galaxy cluster. There are N stars in the cluster where the i th star has a spectral type of S[i].

Mikasa decides to record some of these N stars in her telescope. Eren decides that he will record all the stars left in the cluster after Mikasa has finished.

Find out whether it is possible that Mikasa and Eren end up with exactly same multiset of spectral types.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int a[n];

        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        int flag=1;
        qsort(a, n, sizeof(int), compare);
        for(int k=1;k<n;k+=2){
            if(a[k-1]!=a[k]){
                flag=0;
                break;
            }     
        }
        if (flag&&n%2==0) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }

    return 0;
}
