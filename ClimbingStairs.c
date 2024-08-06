/*ou are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1, 2 or 3 steps. In how many distinct ways can you climb to the top?*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    






    int T;

    scanf("%d", &T);

    for (int t = 0; t < T; ++t) {

        int n;

        scanf("%d", &n);

        int dp[33]; // To handle n up to 32

        dp[0] = 1;

       

        for (int i = 1; i <= n; ++i) {

            dp[i] = dp[i - 1];

            if (i >= 2) {

                dp[i] += dp[i - 2];

            }

            if (i >= 3) {

                dp[i] += dp[i - 3];

            }

        }

        // Print the result for the current test case

        printf("%d\n", dp[n]);

    }

    return 0;

}