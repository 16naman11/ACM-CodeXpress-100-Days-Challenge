/*Om and Ram decided to play an interesting game with their family members to enjoy the weekend, in which they gave everyone tickets consisting of a square matrix. Rules for deciding the winner are- At all the diagonal elements must be non zero All other elements should be zero

Task for you is to design a program which will output whether the participant is the winner or not depending upon the above conditions of the game.*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int m, n;
        scanf("%d %d", &m, &n);

        long int a[m][n];
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%ld", &a[j][k]);
            }
        }

        int flag = 1; 

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if ((j == k || j == n - 1 - k) && a[j][k] == 0) {
                    flag = 0; 
                    break;
                } else if (j != k && j != n - 1 - k && a[j][k] != 0) {
                    flag = 0; 
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }

        if (flag == 1)
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}
