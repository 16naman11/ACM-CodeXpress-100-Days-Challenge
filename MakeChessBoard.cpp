/*You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.

Print the minimum number of moves to transform the board into a chessboard board. If the task is impossible, print -1.

A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.*/

#include <iostream>

#include <vector>

using namespace std;

int minMovesToChessboard(vector<vector<int>>& board) {

    int n = board.size();

    int rowSum = 0, colSum = 0;

    for (int i = 0; i < n; ++i) {

        rowSum += board[0][i];

        colSum += board[i][0];

    }

    if (n % 2 == 0) {

        if (rowSum != n / 2 && rowSum != n / 2 - 1)

            return -1;

        if (colSum != n / 2 && colSum != n / 2 - 1)

            return -1;

    } else {

        if (rowSum != n / 2 && rowSum != n / 2 + 1)

            return -1;

        if (colSum != n / 2 && colSum != n / 2 + 1)

            return -1;

    }

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {

            if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) == 1)

                return -1;

        }

    }

    int rowSwap = 0, colSwap = 0;

    for (int i = 0; i < n; ++i) {

        rowSwap += board[i][0] != i % 2;

        colSwap += board[0][i] != i % 2;

    }

    return min(rowSwap, n - rowSwap) / 2 + min(colSwap, n - colSwap) / 2;

}

int main() {

    int T;

    cin >> T;

    vector<int> results;

    for (int t = 0; t < T; ++t) {

        int n;

        cin >> n;

        vector<vector<int>> board(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < n; ++j) {

                cin >> board[i][j];

            }

        }

        results.push_back(minMovesToChessboard(board));

    }

    for (int result : results) {

        cout << result << endl;

    }

    return 0;

}
