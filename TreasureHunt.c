/*You are an adventurer who has discovered a hidden cave full of gold coins. The cave has n chambers, each containing a positive number of coins. You want to collect as many coins as possible, but there is a catch: the cave is booby-trapped, and you can only take the coins from one chamber at a time. If you take coins from a chamber that has the same number of coins as any previous chamber, the trap will be activated and you will lose everything.

How can you maximize your profit by choosing exactly one subarray of chambers to loot, such that the number of coins in each chamber is unique? The profit you get is equal to the sum of the coins in the subarray.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int testcase = 0; testcase < t; testcase++) {
        int n;
        scanf("%d", &n);

        int chamber[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &chamber[i]);
        }

        
        int uniqueCoins[10001] = {0}; 
        int start = 0, end = 0;
        int maxProfit = 0, currentProfit = 0;

        while (end < n) {
            
            if (uniqueCoins[chamber[end]] == 0) {
                uniqueCoins[chamber[end]] = 1;
                currentProfit += chamber[end];
                end++;
            } else {
                
                uniqueCoins[chamber[start]] = 0;
                currentProfit -= chamber[start];
                start++;
            }
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }

        printf("%d\n", maxProfit);
    }

    return 0;
}
