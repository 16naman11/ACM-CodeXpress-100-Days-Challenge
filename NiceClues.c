/*Imagine you are a detective who has a list of clues called nums and a number called k. Each clue is a number, and some of them are odd and some are even. A sequence of clues is a part of the list that is continuous, meaning there are no gaps between the clues. A sequence of clues is called nice if it has k odd clues in it.

How many nice sequences of clues are there in nums?*/

#include <stdio.h>

int countNiceSequences(int nums[], int n, int k) {
    int count = 0, oddCount = 0, prefix[n + 1];
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 != 0) {
            oddCount++;
        }
        prefix[i + 1] = oddCount;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (prefix[j] - prefix[i] == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int nums[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }

        int result = countNiceSequences(nums, n, k);
        printf("%d\n", result);
    }

    return 0;
}