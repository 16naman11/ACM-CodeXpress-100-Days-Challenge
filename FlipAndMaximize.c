/*Given a binary array nums and an integer k, Print the maximum number of consecutive 1's in the array if you can flip at most k 0's.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        long int k,n;
        int a[100000];
        scanf("%ld %ld", &n, &k);

        for (long int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        long int x, count, max = 0;
        for (long int j = 0; j < n ; j++) {
            x = j;
            long int z = k;
            count = 0;
            int flag=1;
            while (flag && x<n) {
                if (a[x] == 1) {
                    count++;
                    x++;
                } else if(a[x]==0){
                    z--;
                    count++;
                    x++;
                }
                if(z==0&&a[x]==0){
                    flag=0;
                }
            }
            if (count > max)
                max = count;
        }
        printf("%ld\n", max);
    }

    return 0;
}
