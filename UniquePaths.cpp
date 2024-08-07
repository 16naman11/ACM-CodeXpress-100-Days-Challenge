/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, print the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

*/

#include <iostream>

#include <vector>

using namespace std;

int uniquePaths(int m, int n) {

    vector<vector<int>> dp(m, vector<int>(n, 0));

    

    // Base case: there is only one way to reach any cell in the first row or first column

    for (int i = 0; i < m; ++i) {

        dp[i][0] = 1;

    }

    for (int j = 0; j < n; ++j) {

        dp[0][j] = 1;

    }

    

    // Fill up the dp table

    for (int i = 1; i < m; ++i) {

        for (int j = 1; j < n; ++j) {

            dp[i][j] = dp[i-1][j] + dp[i][j-1];

        }

    }

    

    // Return the number of unique paths to the bottom-right corner

    return dp[m-1][n-1];

}

int main() {

    int T;

    cin >> T;

    while (T--) {

        int m, n;

        cin >> m >> n;

        

        cout << uniquePaths(m, n) << endl;

    }

    return 0;

}