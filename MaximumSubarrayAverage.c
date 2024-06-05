/*You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.(Upto 5 digits of decimal)*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void*a, const void*b){
    return(*(int*)b-*(int*)a);
}

int main() {

    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        long int n,k;
        scanf("%ld %ld", &n, &k);
        long int a[n];
        for(int i=0;i<n;i++){
            scanf("%ld", &a[i]);
        }
        long int b[n-k];
        for(int j=0;j<n-k+1;j++){
            long int sum=0;
            for(int x=j;x<j+k;x++){
                sum+=a[x];
            }
            b[j]=sum;
        }
        qsort(b,n-k,sizeof(long int),compare);
        double result=(double)b[0]/k;
        printf("%.5lf\n", result);
    }
    return 0;
}
