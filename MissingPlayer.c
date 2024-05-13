/*During the Cricket World Cup, each participating team is assigned a unique jersey number for their players. The jersey numbers range from 0 to n, where n is the total number of players in the team. The numbers are assigned in a consecutive manner without any duplicates.

You are given an array jerseyNumbers of n elements representing the jersey numbers of the players in a particular team. However, one player's jersey number is missing. Can you write a program to find the missing jersey number?*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int n, a[10000], b[10000];
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int sum=0, asum=0;
        for(int j=0;j<n;j++){
            asum+=a[j];
            sum+=(j+1);
        }
        int diff=sum-asum;
        printf("%d", diff);
        printf("\n");
    }

    return 0;
}
