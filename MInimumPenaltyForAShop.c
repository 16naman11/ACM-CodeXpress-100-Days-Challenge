/*You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour whereas 'N' indicates that no customers come at the ith hour. If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

For every hour when the shop is open and no customers come, the penalty increases by 1. For every hour when the shop is closed and customers come, the penalty increases by 1. Print the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.*/


#include <stdio.h>

// Function to find the earliest hour to close the shop with minimum penalty
int earliest_closing_hour(char *customers) {
    int n = 0;
    while (customers[n] != '\0') {
        n++;
    }

    // Calculate the initial penalty with the shop closing at hour 0
    int penalty = 0;
    for (int i = 0; i < n - 1; i++) {
        if (customers[i] == 'N') {
            penalty++;
        }
        if (customers[i] == 'Y') {
            penalty--;
        }
    }
    int min_penalty = penalty;
    int closing_hour = 0;

    // Iterate through each possible closing hour
    for (int i = 1; i <= n; i++) {
        // Update penalty based on the change in closing hour
        if (customers[i - 1] == 'N') {
            penalty++;
        }
        if (customers[i - 1] == 'Y') {
            penalty--;
        }
        if (customers[i - 1] == 'Y' && customers[i - 1] == 'N') {
            penalty++;
        }

        // Check if the updated penalty is smaller than the minimum penalty
        if (penalty < min_penalty) {
            min_penalty = penalty;
            closing_hour = i;
        }
    }

    return closing_hour;
}

int main() {
    // Input the number of test cases
    int T;
    scanf("%d", &T);

    // Process each test case
    for (int t = 0; t < T; t++) {
        // Input the customer string
        char customers[100001];
        scanf("%s", customers);

        // Find the earliest closing hour and print the result
        int result = earliest_closing_hour(customers);
        printf("%d\n", result);
    }

    return 0;
}