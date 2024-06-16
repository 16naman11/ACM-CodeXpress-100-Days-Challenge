/*You are standing at position 0 on an infinite number line. There is a destination at position target.

You can make some number of moves numMoves so that:

On each move, you can either go left or right.
During the ith move (starting from i == 1 to i == numMoves), you take i steps in the chosen direction.
Given the integer target, print the minimum number of moves required (i.e., the minimum numMoves) to reach the destination.*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {

    int T;

    scanf("%d", &T);

    while (T--) {

        int target;

        scanf("%d", &target);

        target = (target < 0) ? -target : target;

        int moves = 0, sum = 0;

        while (sum < target || (sum - target) % 2 != 0) {

            moves++;

            sum += moves;

        }

        printf("%d\n", moves);

    }

    return 0;

}


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    


