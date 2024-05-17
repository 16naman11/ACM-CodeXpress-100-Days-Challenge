/*The Cricket World Cup final is just around the corner, and teams are gearing up for a special pairing competition. Each team has a roster of players, each identified by a unique jersey number. In this competition, players need to be paired up into n/2 pairs, and the challenge is to minimize the maximum pair sum.

The pair sum of a pair (a, b) is equal to a + b. For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.

Given an array jerseyNumber of even length n in which each element represent the jersey number of the particular player, pair up the players into n / 2 pairs such that:

Each player is in exactly one pair.
The maximum pair sum is minimized.
Output the minimized maximum pair sum after optimally pairing up the players.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void*a,const void*b){
    return (*(int*)a-*(int*)b);
}
int main() {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d", &n);
        int half=n/2;
        long int a[n], b[half];
        for(int j=0;j<n;j++){
            scanf("%ld", &a[j]);
        }
        
        qsort(a,n,sizeof(long int),compare);
        for(int k=0;k<half;k++){
            b[k]=a[k]+a[n-k-1];
        }
        qsort(b,half,sizeof(long int),compare);
        printf("%ld\n", b[half-1]);
        
    }
    return 0;
}
