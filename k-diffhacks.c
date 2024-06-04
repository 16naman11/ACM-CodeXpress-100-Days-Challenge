/*You are a hacker who has infiltrated a secret facility that stores an array of integers nums and an integer k. You want to find out how many unique k-diff pairs are hidden in the array.

A k-diff pair is a pair of numbers (nums[i], nums[j]) that satisfy the following conditions:

0 <= i, j < nums.length i != j.
The absolute difference between nums[i] and nums[j] is equal to k.
The absolute difference is calculated as |val|, which means the positive value of val.
How many unique k-diff pairs can you discover in the array?*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void*a, const void*b){
    return(*(int*)a-*(int*)b);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int n,k;
        scanf("%d %d",&n,&k);
        int a[n];
        for(int l=0;l<n;l++){
            scanf("%d", &a[l]);
        }
        int min=0;
        qsort(a,n,sizeof(int),compare);
        for(int x=1;x<n;x++){
            if(a[x]==a[x-1]){
                a[x-1]=10001;
                min++;
            }
        }
        qsort(a,n,sizeof(int),compare);
        n-=min;
        int result=0;
        for(int x=0;x<n;x++){
            for(int p=0;p<n;p++){
                if(x==p)
                    continue;
                else if(abs(a[p]-a[x])==k)
                    result++;
            }
        }
        printf("%d \n", result/2);
    }
    return 0;
}
