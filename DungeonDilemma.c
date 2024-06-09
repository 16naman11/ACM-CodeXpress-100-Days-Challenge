/*You are exploring a dungeon that has a single row of treasure chests arranged from left to right. The chests are represented by an integer array treasures where treasures[i] is the type of treasure the ith chest contains.

You want to collect as much treasure as possible. However, the dungeon has some strict rules that you must follow:

You only have two bags, and each bag can only hold a single type of treasure. There is no limit on the amount of treasure each bag can hold.
Starting from any chest of your choice, you must open exactly one chest from every chest (including the start chest) while moving to the right. The opened treasures must fit in one of your bags.
Once you reach a chest with treasure that cannot fit in your bags, you must stop.
Given the integer array treasures, print the maximum number of treasures you can open.*/


#include <stdio.h>

int max_treasures(int n, int a[]) {
    int max = 0;

    for (int i = 0; i < n; i++) {
        int count = 0, sum = 0;
        int bag1 = a[i], bag2 = -1;

        for (int j = i; j < n; j++) {
            if (a[j] == bag1 || a[j] == bag2) {
                sum++;
                if (a[j] != bag1) {
                    bag2 = a[j];
                }
            } else {
                count++;
                if (count > 1) {
                    break;
                }
                sum++;
                bag2 = a[j];
            }

            if (sum > max) {
                max = sum;
            }
        }
    }

    return max;
}

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

        int result = max_treasures(n, a);
        printf("%d\n", result);
    }

    return 0;
}
