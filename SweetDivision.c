/*Raj and Priya love celebrating Diwali by giving sweets to their neighbors. This year, they have an array of positive integers L that represents the number of sweets they gave to each house on their street. Raj wants to know if there's a house in the street where, if you split the array into two parts at that house, both parts would have the same total number of sweets. In other words, he wants to find a house where they can say they've divided the sweets equally. Help Raj in finding the house following the above mentioned conditions by writing the program which -

Print the index of the house, if such a house exists.
Print -1 if no such house exists.
If there are multiple such houses, the program should print the index of the leftmost one.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    for(int i=0;i<T;i++) {
        int N;
        scanf("%d", &N);
        int L[10000];
        for (int i = 0; i < N; i++) {
            scanf("%d", &L[i]);
        }
        int total_sum = 0;
        for (int i = 0; i < N; i++) {
            total_sum += L[i];
        }
        int l_sum = 0;
        int r_sum = total_sum;
        int found = 0;
        int result = -1;
        for (int i = 0; i < N; i++) {
            r_sum -= L[i];
            if (l_sum == r_sum) {
                result = i;
                found = 1;
                break;
            }
            l_sum += L[i];
        }

        if (found) {
            printf("%d\n", result);
        } else {
            printf("-1\n");
        }
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}