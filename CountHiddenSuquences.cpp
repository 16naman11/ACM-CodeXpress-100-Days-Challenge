/*You are given a 0-indexed array of n integers differences, which describes the differences between each pair of consecutive integers of a hidden sequence of length (n + 1). More formally, call the hidden sequence hidden, then we have that differences[i] = hidden[i + 1] - hidden[i].

You are further given two integers lower and upper that describe the inclusive range of values [lower, upper] that the hidden sequence can contain.

For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).

[3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
[5, 6, 3, 7] is not possible since it contains an element greater than 6.
[1, 2, 3, 4] is not possible since the differences are not correct.
Print the number of possible hidden sequences there are. If there are no possible sequences, Print 0*/


#include <iostream>
#include <vector>

using namespace std;

int countHiddenSequences(const vector<int>& differences, int lower, int upper) {
    int n = differences.size();
    vector<vector<int>> dp(n + 1, vector<int>(upper - lower + 1, 0));

    // Base cases: starting elements within range
    for (int val = lower; val <= upper; ++val) {
        dp[0][val - lower] = 1;
    }

    // Iterate through differences and possible starting values
    for (int i = 1; i <= n; ++i) {
        for (int val = lower; val <= upper; ++val) {
            // Check for valid starting value within range, considering both lower and upper bounds
            if (val - differences[i - 1] >= lower && val - differences[i - 1] <= upper) {
                dp[i][val - lower] = dp[i - 1][val - differences[i - 1] - lower];
            }
        }
    }

    // Sum counts for all possible ending values
    int count = 0;
    for (int val = lower; val <= upper; ++val) {
        count += dp[n][val - lower];
    }

    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, lower, upper;
        cin >> n >> lower >> upper;

        vector<int> differences(n);
        for (int i = 0; i < n; ++i) {
            cin >> differences[i];
        }

        int result = countHiddenSequences(differences, lower, upper);
        cout << result << endl;
    }

    return 0;
}