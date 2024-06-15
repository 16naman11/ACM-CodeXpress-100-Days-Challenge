/*You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Print x if the array is special, otherwise, Print -1. It can be proven that if nums is special, the value for x is unique.*/

#include <stdio.h>
#include <stdlib.h>



int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int res=-1,j=0;

        for(int i=1;i<=n;i++){
            int count=0;
            for(j=0;j<n;j++){
                if(a[j]>=i){
                    count++;
                }
            }
            if(count==i  && count>res){
                res=count;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}


